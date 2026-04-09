#include "UART_interface.h"

// No #include <xc.h> needed in mikroC

void UART_Init(void)
{
    SPBRG = ((8000000UL / (16UL * 9600UL)) - 1);  // Baud rate
    TXSTA.B2 = 1;  // BRGH = 1
    TXSTA.B5 = 1;  // TXEN = 1
    RCSTA.B7 = 1;  // SPEN = 1
    RCSTA.B4 = 1;  // CREN = 1
}

void UART_SendChar(char d)
{
    while(!PIR1.TXIF);  // Wait until TX ready
    TXREG = d;
}

char UART_ReceiveChar(void)
{
    while(!PIR1.RCIF);  // Wait until RX ready
    return RCREG;
}

void UART_SendString(char* str)
{
    while(*str)
    {
        UART_SendChar(*str);
        str++;
    }
}