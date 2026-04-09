#include "../MCAL/UART/UART_interface.h"
#include "../SERVICES/STD_TYPES.h"

void UART_Test(void)
{
    u8 received_data;

    UART_Init();

    while(1)
    {
        /* --- Send a character --- */
        UART_SendChar('A');
         Delay_ms(500);
    }
}