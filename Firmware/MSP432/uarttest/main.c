/* www.microDigitalEd.com
 * p4_3.c UART2 transmit
 *
 * Sending a string "Hello\r\n" to UART2 on MSP432 LaunchPad.
 * The UART2 is connected to P3.2 (RXD) and P3.3 (TXD) on the LaunchPad.
 * A 3.3V signal level to USB cable is used to connect to
 * the host PC COM port.
 * Use TeraTerm to see the message "Hello" on a PC.
 *
 * By default the subsystem master clock is 3 MHz.
 * Setting EUSCI_A2->BRW=26 with oversampling disabled yields 115200 Baud.
 *
 * Tested with Keil 5.20 and MSP432 Device Family Pack V2.2.0
 * on XMS432P401R Rev C.
 */

#include "msp.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void UART2_init(void);
void delayMs(int n);

int main(void) {
    char message[] = "INSERT INTO flowrate VALUES ('22', '2022-4-27 11:45:00+00')\r\n";
    //INSERT INTO flowrate VALUES ('16', '2022-4-20 01:05:00+00')
    unsigned char RECEIVED_DATA;
    int i;

    UART2_init();

    while (1) {
        //measurement

        for (i = 0; i < 61; i++) {
            while(!(EUSCI_A2->IFG & 0x02)) { }  /* wait for transmit buffer empty */
            EUSCI_A2->TXBUF = message[i]; /* send a char */
            //printf("data was sent.\n");
            EUSCI_A2->IFG |= 0x01;
            delayMs(10);
        }
//        for (i = 0; i < 61; i++) {
//                while(!(EUSCI_A2->IFG & 0x02)) { }  /* wait for transmit buffer empty */
//                EUSCI_A2->TXBUF = message[i]; /* send a char */
//                //printf("data was sent.\n");
//                EUSCI_A2->IFG |= 0x01;
//                delayMs(10);
//        }

        //receive data
        while(!(EUSCI_A2->IFG & 0x01)) { }  /* wait until receive buffer is full */
        RECEIVED_DATA = EUSCI_A2->RXBUF;       /* read the receive char and to variable */
        delayMs(20); /* leave a gap between messages */
        EUSCI_A2->CTLW0 |= 1; //reset control register
        EUSCI_A2->CTLW0 &= ~1; //take out of reset mode

        printf("Data in receive buffer: %c\n", RECEIVED_DATA);

        //case statement
//        if (RECEIVED_DATA == '3') {
//            printf("Received data is a flowrate measurement.\n");
//        }-
//        else if (RECEIVED_DATA == '2') {
//            printf("Received data is a temperature measurement.\n");
//        }
//        else if (RECEIVED_DATA == '1') {
//            printf("Received data is a pressure measurement.\n");
//        }
//        else {
//            printf("ERROR: Received data is in unknown format.\n");
//        }
    }


      WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;   // stop watchdog timer
      delayMs(1000);
}

void UART2_init(void) {
    EUSCI_A2->CTLW0 |= 1;       /* put in reset mode for config */
    EUSCI_A2->MCTLW = 0;        /* disable oversampling */
    EUSCI_A2->CTLW0 = 0x0081;   /* 1 stop bit, no parity, SMCLK, 8-bit data */
    EUSCI_A2->BRW = 26;         /* 3,000,000 / 115200 = 26 */
    P3->SEL0 |= 0x0C;           /* P3.3, P3.2 for UART */
    P3->SEL1 &= ~0x0C;
    EUSCI_A2->CTLW0 &= ~1;      /* take UART out of reset mode */
}

/* delay milliseconds when system clock is at 3 MHz */
void delayMs(int n) {
    int i, j;

    for (j = 0; j < n; j++)
        for (i = 750; i > 0; i--);      /* Delay */
}
