#include "uart_test.h"
#include "../MCAL/UART/UART_interface.h"

void UART_Test(void)
{
    UART_Init();
    UART_SendString("UART Test Started...\n");

    while(1)
    {
        char received = UART_ReceiveChar();
        UART_SendChar(received);
    }
}