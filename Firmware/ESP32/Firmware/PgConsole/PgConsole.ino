#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#else

// Uncomment line below if you use WiFi shield instead of Ethernet
#define USE_ARDUINO WIFI 1
#define RXD2 16
#define TXD2 17

#ifdef USE_ARDUINO_WIFI
#include <WIFI.h>
#else
#include <Ethernet.h>
#endif

#endif
#include <SimplePgSQL.h>



IPAddress PGIP(18,223,247,30);        // your PostgreSQL server IP

const char ssid[] = "SSID";      //  your network SSID (name)
const char pass[] = "password";      // your network password

const char user[] = "ubuntu";       // your database user
const char password[] = "password";   // your database password
const char dbname[] = "test_database";         // your database name

const byte bufferSize = 60;
//char serialBuffer[bufferSize] = "INSERT INTO flowrate VALUES ('33', '2022-04-26 12:44:40')";
char serialBuffer[bufferSize];
byte bufferIndex = 0;
char EOL = '\n';
bool hasData = false;

#if defined(ESP8266) || defined(USE_ARDUINO_WIFI) || defined(ESP32)
int WiFiStatus;
WiFiClient client;
#else
#define USE_ARDUINO_ETHERNET 1
EthernetClient client;
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // your mac address
byte ip[] = {192, 168, 1, 177};                    // your IP address
#endif

char buffer[1024];
PGconnection conn(&client, 0, 1024, buffer);

void setup(void)
{
    Serial.begin(
#ifdef __AVR__
    9600
#else
    115200
#endif
    );
    Serial2.begin(115200, SERIAL_8N1, 16, 17);
#ifdef USE_ARDUINO_ETHERNET
    Ethernet.begin(mac, ip);
#else
    WiFi.begin((char *)ssid, pass);
#endif
}

#ifndef USE_ARDUINO_ETHERNET
void checkConnection()
{
    int status = WiFi.status();
    if (status != WL_CONNECTED) {
        if (WiFiStatus == WL_CONNECTED) {
            Serial.println("Connection lost");
            WiFiStatus = status;
        }
    }
    else {
        if (WiFiStatus != WL_CONNECTED) {
            Serial.println("Connected");
            WiFiStatus = status;
        }
    }
}

#endif

static PROGMEM const char query_rel[] = "\
SELECT a.attname \"Column\",\
  pg_catalog.format_type(a.atttypid, a.atttypmod) \"Type\",\
  case when a.attnotnull then 'not null ' else 'null' end as \"null\",\
  (SELECT substring(pg_catalog.pg_get_expr(d.adbin, d.adrelid) for 128)\
   FROM pg_catalog.pg_attrdef d\
   WHERE d.adrelid = a.attrelid AND d.adnum = a.attnum AND a.atthasdef) \"Extras\"\
 FROM pg_catalog.pg_attribute a, pg_catalog.pg_class c\
 WHERE a.attrelid = c.oid AND c.relkind = 'r' AND\
 c.relname = %s AND\
 pg_catalog.pg_table_is_visible(c.oid)\
 AND a.attnum > 0 AND NOT a.attisdropped\
    ORDER BY a.attnum";

static PROGMEM const char query_tables[] = "\
SELECT n.nspname as \"Schema\",\
  c.relname as \"Name\",\
  CASE c.relkind WHEN 'r' THEN 'table' WHEN 'v' THEN 'view' WHEN 'm' THEN 'materialized view' WHEN 'i' THEN 'index' WHEN 'S' THEN 'sequence' WHEN 's' THEN 'special' WHEN 'f' THEN 'foreign table' END as \"Type\",\
  pg_catalog.pg_get_userbyid(c.relowner) as \"Owner\"\
 FROM pg_catalog.pg_class c\
     LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace\
 WHERE c.relkind IN ('r','v','m','S','f','')\
      AND n.nspname <> 'pg_catalog'\
      AND n.nspname <> 'information_schema'\
      AND n.nspname !~ '^pg_toast'\
  AND pg_catalog.pg_table_is_visible(c.oid)\
 ORDER BY 1,2";

int pg_status = 0;

void doPg(char queryInput[])
{
    Serial.println("Connecting to database...");
    char *msg;
    int rc;
    if (!pg_status) {
        conn.setDbLogin(PGIP,
            user,
            password,
            dbname,
            "utf8");
        pg_status = 1;
        return;
    }

    if (pg_status == 1) {
        rc = conn.status();
        if (rc == CONNECTION_BAD || rc == CONNECTION_NEEDED) {
            char *c=conn.getMessage();
            if (c) Serial.println(c);
            pg_status = -1;
        }
        else if (rc == CONNECTION_OK) {
            pg_status = 2;
            Serial.println("Connection Ok");
        }
        return;
    }
    if (pg_status == 2) {
        //if (!Serial.available()) return;
        char *inbuf;
        inbuf = queryInput;
//        int n = Serial.readBytesUntil('\n',inbuf,63);
//        while (n > 0) {
//            if (isspace(inbuf[n-1])) n--;
//            else break;
//        }
//        inbuf[n] = 0;
        Serial.print("Sending: ");
        Serial.println(inbuf);

        if (!strcmp(inbuf,"\\d")) {
            if (conn.execute(query_tables, true)) goto error;
            Serial.println("Working...");
            pg_status = 3;
            return;
        }
        if (!strncmp(inbuf,"\\d",2) && isspace(inbuf[2])) {
            char *c=inbuf+3;
            while (*c && isspace(*c)) c++;
            if (!*c) {
                if (conn.execute(query_tables, true)) goto error;
                Serial.println("Working...");
                pg_status = 3;
                return;
            }
            if (conn.executeFormat(true, query_rel, c)) goto error;
            Serial.println("Working...");
            pg_status = 3;
            return;
        }

        if (!strncmp(inbuf,"exit",4)) {
            conn.close();
            Serial.println("Thank you");
            pg_status = -1;
            return;
        }
        if (conn.execute(inbuf)) goto error;
        Serial.println("Working...");
        pg_status = 3;
    }
    if (pg_status == 3) {
        rc=conn.getData();
        int i;
        if (rc < 0) goto error;
        if (!rc) return;
        if (rc & PG_RSTAT_HAVE_COLUMNS) {
            for (i=0; i < conn.nfields(); i++) {
                if (i) Serial.print(" | ");
                Serial.print(conn.getColumn(i));
            }
            Serial.println("\n==========");
        }
        else if (rc & PG_RSTAT_HAVE_ROW) {
            for (i=0; i < conn.nfields(); i++) {
                if (i) Serial.print(" | ");
                msg = conn.getValue(i);
                if (!msg) msg=(char *)"NULL";
                Serial2.write(msg);
            }
            Serial.println();
        }
        else if (rc & PG_RSTAT_HAVE_SUMMARY) {
            Serial.print("Rows affected: ");
            Serial.println(conn.ntuples());
        }
        else if (rc & PG_RSTAT_HAVE_MESSAGE) {
            msg = conn.getMessage();
            if (msg) Serial.println(msg);
        }
        if (rc & PG_RSTAT_READY) {
            pg_status = 2;
            Serial.println("Sending Next Message...");
        }
    }
    return;
error:
    msg = conn.getMessage();
    if (msg) Serial.println(msg);
    else Serial.println("UNKNOWN ERROR");
    if (conn.status() == CONNECTION_BAD) {
        Serial.println("Connection is bad");
        pg_status = -1;
    }
}

void listenForData()
{
  char recievedData;

  while(Serial2.available() > 0 && !hasData){
    recievedData = Serial2.read();

    if (recievedData != EOL){
      serialBuffer[bufferIndex++] = recievedData;
      if (bufferIndex >= bufferSize){
        bufferIndex = bufferSize - 1;
      }
    }
    else
    {
      serialBuffer[bufferIndex] = '\0'; //terminate string
      bufferIndex = 0;
      //hasData = true;
      Serial.print("Input: ");
      Serial.println(serialBuffer);
    }
  }
}


void loop()
{
#ifndef USE_ARDUINO_ETHERNET
    checkConnection();
    if (WiFiStatus == WL_CONNECTED) {
#endif

        listenForData();
        doPg(serialBuffer);
        //Serial.println("Moving on to constraints...");
        //char constraints[] = "SELECT minflowrate FROM constraints";
        //doPg(constraints);
        
#ifndef USE_ARDUINO_ETHERNET
    }
#endif
    delay(500);
}
