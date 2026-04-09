#include "UART_interface.h"

void UART_Test(void)
{
    UART_voidInit();

    while(1)
    {
        UART_voidSendChar('A'); // keep sending A
    }
}