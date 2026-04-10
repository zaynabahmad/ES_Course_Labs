// Purpose: Sends/receives data to/from computer via USB-serial
// Used for debugging and communication with PC

#include "uart.h"

void UART_Init(uint32 baud_rate) {
    // For 8MHz PIC at 9600 baud:
    // SPBRG = (FOSC/(64*Baud)) - 1 = (8000000/(64*9600))-1 = 12

    TRISCbits.TRISC6 = 0;  // TX pin as output
    TRISCbits.TRISC7 = 1;  // RX pin as input

    SPBRG = (_XTAL_FREQ / (64 * baud_rate)) - 1;
    TXSTAbits.BRGH = 0;    // Low speed
    TXSTAbits.SYNC = 0;    // Asynchronous mode
    TXSTAbits.TXEN = 1;    // Enable transmit
    RCSTAbits.SPEN = 1;    // Enable serial port
    RCSTAbits.CREN = 1;    // Enable receive
}

void UART_WriteChar(uint8 data) {
    while(!TXSTAbits.TRMT);  // Wait for buffer empty
    TXREG = data;             // Send character
}

void UART_WriteString(char* str) {
    while(*str) {
        UART_WriteChar(*str++);  // Send each character
    }
}

uint8 UART_ReadChar(void) {
    while(!PIR1bits.RCIF);  // Wait for data
    return RCREG;            // Read character
}

uint8 UART_DataReady(void) {
    return PIR1bits.RCIF;    // Return 1 if data available
}