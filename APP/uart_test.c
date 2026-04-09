#include "../MCAL/UART/UART_interface.h"

void UART_Test()
{
    UART_Init();

    while (1)
    {
        char data = UART_ReceiveChar();
        UART_SendChar(data); // echo
    }
}