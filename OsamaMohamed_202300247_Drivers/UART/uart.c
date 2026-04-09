/*
 * uart.c
 * UART (EUSART) Driver for PIC16F877A — polling mode
 * TX = RC6, RX = RC7
 */

#include "uart.h"
#include "../common_macros.h"

void UART_init(const UART_Config *config) {
    /* RC6 (TX) output, RC7 (RX) input */
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;

    /* Baud rate: BRGH=1 (High Speed mode)
       SPBRG = (F_CPU / (16 * BaudRate)) - 1 */
    uint16 spbrg = (uint16)((F_CPU / (16UL * config->baudRate)) - 1);
    SPBRG = (uint8)spbrg;

    /* TXSTA: TXEN=1, BRGH=1, 8-bit or 9-bit */
    TXSTA = 0x00;
    TXSTAbits.TXEN = 1;   /* Enable transmitter */
    TXSTAbits.BRGH = 1;   /* High baud rate     */
    if (config->dataBits == UART_9BIT_DATA)
        TXSTAbits.TX9 = 1;

    /* RCSTA: SPEN=1 (enables RC6/RC7), CREN=1 (continuous receive) */
    RCSTA = 0x00;
    RCSTAbits.SPEN = 1;
    RCSTAbits.CREN = 1;
    if (config->dataBits == UART_9BIT_DATA)
        RCSTAbits.RX9 = 1;
}

void UART_sendByte(uint8 data) {
    while (!TXSTAbits.TRMT);  /* Wait until TSR (shift register) is empty */
    TXREG = data;
}

uint8 UART_receiveByte(void) {
    while (!PIR1bits.RCIF);   /* Wait until data is received */
    return RCREG;
}

void UART_sendString(const char *str) {
    while (*str)
        UART_sendByte((uint8)(*str++));
}

void UART_receiveString(char *buf, uint8 maxLen) {
    uint8 i = 0;
    char c;
    while (i < maxLen - 1) {
        c = (char)UART_receiveByte();
        if (c == '\n') break;
        buf[i++] = c;
    }
    buf[i] = '\0';
}
