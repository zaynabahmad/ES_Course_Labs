#include "../MCAL/UART/UART_Interface.h"

void UART_Test(void)
{
    unsigned long i;   // ? declare here

    UART_Init();

    while(1)
    {
        UART_WriteString("Hello UART\r\n");

        for(i = 0; i < 50000; i++);   // delay
    }
}