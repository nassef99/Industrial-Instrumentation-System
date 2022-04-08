#include "Energia.h"

#line 1 "C:/Users/hpi/workspace_v11/iis_mcu/iis_mcu.ino"

#if defined(ENERGIA) 
#include "Energia.h"
#else 
#include "Arduino.h"
#endif


#include "SPI.h"
#include "msp.h"
#include "stdio.h"
#include "PDLS_EXT3_Basic.h"


void wait(uint8_t second);
void testDisplay();
void testShapes();
void displayTitle();
void displayFlowrate();
void displayPressure();
void displayTemperature();
void select_ADC_channel(unsigned char selected_channel, unsigned char *index, unsigned char *sub_channel);
void setup();
void loop();

#line 15
Screen_EPD_EXT3 myScreen(eScreen_EPD_EXT3_417, boardLaunchPad);

void wait(uint8_t second)
{
    for (uint8_t i = second; i > 0; i--)
    {
        Serial.print(formatString(" > %i  \r", i));
        delay(1000);
    }
    Serial.print("         \r");
}

void testDisplay()
{
  uint16_t x, y;
  x = 6;
  y = 6;
  myScreen.selectFont(Font_Terminal8x12);
  
  
  myScreen.gText(x, y, "Industrial Instrumentation System!");
  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Latest Flowrate: 10");
  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Latest Pressure: 70");
  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Latest Temperature: 84.9");

  myScreen.flush();
}

void testShapes()
{
  uint16_t x, y, z, dx, dy, dz;
  x = myScreen.screenSizeX();
  y = myScreen.screenSizeY();
  dx = x / 6;
  dy = y / 6;
  z = min(x, y);
  dz = min(dx, dy);

  
  myScreen.setPenSolid(true);
  myScreen.dRectangle(dx, dy * 2, dx + 1, dy * 3, myColours.red);
  myScreen.circle(dx * 1.5, dy - 1, 30, myColours.red);

  
  myScreen.triangle(dx * 2.5, dy * 5, dx * 3.5, dy * 2, dx * 3.5, dy * 5, myColours.grey);
  myScreen.triangle((dx * 2.5) - 1, dy * 5, dx * 2.5, dy * 2, (dx * 3.5) - 1, dy * 2, myColours.lightRed);
  myScreen.circle(dx * 3, dy - 1, 30, myColours.lightRed);

  myScreen.flush();
}

void displayTitle()
{
  myScreen.selectFont(Font_Terminal12x16);
  myScreen.gText(100, 50, "Team 45 Presents:");
  myScreen.gText(130, 100, "Industrial");
  myScreen.gText(100, 150, "Instrumentation");
  myScreen.gText(150, 200, "System");

  myScreen.flush();
}

void displayFlowrate()
{
  uint16_t x, y;
  x = 6;
  y = 10;
  myScreen.selectFont(Font_Terminal12x16);

  myScreen.gText(x, y, "Latest Flowrate:");
  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "10 (gallons per second)", myColours.grey);

  y += 4 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Reading occured at:");

  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "2021 - 11 - 20, 1:30 PM", myColours.grey);

  y += 4 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Time until capacity reached:");

  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "< 1 minute", myColours.grey);

  myScreen.flush();
}

void displayPressure()
{
  uint16_t x, y;
  x = 6;
  y = 10;
  myScreen.selectFont(Font_Terminal12x16);

  myScreen.gText(x, y, "Latest Pressure:");
  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "70 (psi)", myColours.grey);

  y += 4 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Reading occured at:");

  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "2021-11-20, 1:49 PM", myColours.grey);

  y += 4 * myScreen.characterSizeY();
  myScreen.gText(x, y, "WARNING!", myColours.red);

  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "MAX PRESSURE REACHED!", myColours.red);

  myScreen.flush();
}

void displayTemperature()
{
  uint16_t x, y;
  x = 6;
  y = 10;
  myScreen.selectFont(Font_Terminal12x16);

  myScreen.gText(x, y, "Latest Temperature:");
  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "84.7 (degrees Fahrenheit)", myColours.grey);

  y += 4 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Reading occured at:");

  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "2021 - 11 - 20, 1:47 PM", myColours.grey);

  y += 4 * myScreen.characterSizeY();
  myScreen.gText(x, y, "Current Max Temperature:");

  y += 2 * myScreen.characterSizeY();
  myScreen.gText(x, y, "100 (degrees Fahrenheit)", myColours.grey);

  myScreen.flush();
}








void select_ADC_channel(unsigned char selected_channel, unsigned char *index, unsigned char *sub_channel)
{
    switch(selected_channel)
    {
        case 1:
            *sub_channel = 0x10;
            *index = 1;
            break;

        case 2:
            *sub_channel = 0x10;
            *index = 1;
            break;

        case 3:
            *sub_channel = 0x10;
            *index = 1;
            break;

        case 4:
            *sub_channel = 0x10;
            *index = 1;
            break;

        case 5:
            *sub_channel = 0x10;
            *index = 1;
            break;

        case 6:
            *sub_channel = 0x10;
            *index = 1;
            break;
        default:
        case 0:
            *sub_channel = 0x00;
            *index = 1;
            break;
    }

}

void setup() {
  
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("Hello World!");

  
  Serial.println("Beginning display...");
  myScreen.begin();
  myScreen.setOrientation(7);

  
  testShapes();
  myScreen.clear();

  
  
  

  
  
  
  
  
  
  
  

  
  
}

void loop() {
  
  


    

    
    TIMER_A0->CTL = 0x02D1;     
    TIMER_A0->EX0 = 7;          
    TIMER_A0->CCR[0] = 46875 - 1;   

    TIMER_A1->CTL = 0x02D1;     
    TIMER_A1->EX0 = 7;          
    TIMER_A1->CCR[0] = 46875 - 1;   

    TIMER_A2->CTL = 0x02D1;     
    TIMER_A2->EX0 = 7;          
    TIMER_A2->CCR[0] = 46875 - 1;   

    TIMER_A3->CTL = 0x02D1;     
    TIMER_A3->EX0 = 7;          
    TIMER_A3->CCR[0] = 46875 - 1;   

    
    

    while (1) {
            while((TIMER_A1->CCTL[0] & 1) == 0);    
            TIMER_A1->CCTL[0] &= ~1;                
            P2->OUT ^= 1;                           
    }

    

    
    EUSCI_A0 ->CTLW0 |=1; 
    EUSCI_A0 ->MCTLW = 0;
    EUSCI_A0->CTLW0 |=0x80; 
    EUSCI_A0->BRW = 26; 
    P1->SEL0 |=0x0C;
    P1->SEL1 &= ~0x0C;
    EUSCI_A0 ->CTLW0 &=~0x01; 

    
    char word[20];
    float x = 1.234;
    float y = 5.678;
    float z = 9.123;
    sprintf(word, "%.3f degrees, %.3f psi, %.3f gallons per second\n\r");
    int i = 0;
    while(word[i]) {
        EUSCI_A0 ->TXBUF = word[i];
        while((EUSCI_A0->IFG & 2)==0) {
            
        }
        i++;
    }

    
    while(1) {
        if ((EUSCI_A0 ->IFG & 1) != 0) {
            word[i]=EUSCI_A0->RXBUF; 
            if (word[i] == '\r') 
            {
                word[i] = '\0';
                break;
            }
            else
            {
                i++;
            }
        }
    }

    int ans = atoi(word); 
    ans = ans * 2; 
    sprintf(word, "%d\r\n", ans); 


    

  
  delay(1000);
}



