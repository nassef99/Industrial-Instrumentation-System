#include <Wifi.h>;
#define RXD2 16;
#define TXD2 17;

const char* ssid = "enter-ssid"
const char* password = "enter-password"

void setup() {
  // put your setup code here, to run once:
  //Initialize UART0, with a 115200 baud rate
  Serial.begin(115200);
  //Setup Wifi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to the WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  //Initialize serial 2 (baud-rate, protocol, RX pin, TX pin)
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  //Read serial2 using Serial2.readString()
  //Delay for a second before sending a new message to the database
  delay(1000);
  

}
