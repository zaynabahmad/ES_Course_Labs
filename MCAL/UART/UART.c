#include "../../SERVICES/STD_TYPES.h"
#include "UART_interface.h"

void UART_Init(void)
{
    // TX (RC6) output, RX (RC7) input
    TRISC6_bit = 0;
    TRISC7_bit = 1;

    // Baud rate = 9600 for 8MHz
    SPBRG = 12;

    // TXSTA: async mode, TX enable
    TXSTA = 0x20;

    // RCSTA: serial enable + continuous receive
    RCSTA = 0x90;
}

void UART_SendByte (u8 u8Data)
{
    while(!TXIF_bit);  // wait until buffer empty
    TXREG = u8Data;
}

u8 UART_ReceiveByte(void)
{
    while(!RCIF_bit);   // wait until data received
    return RCREG;
}

// RAM string
void UART_SendString(char *str)
{
    while(*str)
    {
        UART_SendByte(*str++);
    }
}

// ROM string (for "text")
void UART_SendString_ROM(const char code *str)
{
    while(*str)
    {
        UART_SendByte(*str++);
    }
}