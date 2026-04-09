#include "UART_private.h"

// Initialize UART (9600 baud, 8-bit)
void UART_Init()
{
    // Set baud rate = 9600 (for 8MHz)
    UBRRL = 51;

    // Enable TX & RX
    UCSRB |= (1 << 3) | (1 << 4);

    // 8-bit data
    UCSRC |= (1 << 1) | (1 << 2);
}

// Send character
void UART_SendChar(char data)
{
    // Wait until buffer empty
    while (!(UCSRA & (1 << 5)));

    UDR = data;
}

// Receive character
char UART_ReceiveChar()
{
    // Wait until data received
    while (!(UCSRA & (1 << 7)));

    return UDR;
}