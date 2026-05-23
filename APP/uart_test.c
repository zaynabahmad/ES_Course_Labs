#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\UART\UART_interface.h"

void UART_Test(void)
{
    unsigned char received;
    unsigned char status;

    UART_voidInit();

    while (1)
    {
        UART_voidSendString((const unsigned char *)"Hello\r\n");

        status = UART_u8ReceiveCharTimeout(&received);
        if (status == UART_OK)
        {
            UART_voidSendChar(received);
        }
    }
}