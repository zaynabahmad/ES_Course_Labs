
#include "../MCAL/UART/UART_interface.h"
#include "../SERVICES/DELAY/DELAY_interface.h"

void APP_UART_Test(void)
{
    UART_Init(9600);

    while(1)
    {
        UART_WriteText("UART Test OK");
        UART_WriteNewLine();
        Delay_ms(1000);
    }
}