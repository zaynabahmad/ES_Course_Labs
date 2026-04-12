#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/USART/USART_Interface.h"

void UART_Test(void)
{
    u8 i;
    u32 j;

    UART_RX_Init();
    UART_TX_Init();

    // Send "TEST" message
    UART_Write('T');
    for (j = 0; j < 5000; j++);

    UART_Write('E');
    for (j = 0; j < 5000; j++);

    UART_Write('S');
    for (j = 0; j < 5000; j++);

    UART_Write('T');
    for (j = 0; j < 5000; j++);

    UART_Write('\r');
    for (j = 0; j < 5000; j++);

    UART_Write('\n');
    for (j = 0; j < 10000; j++);

    // Send number sequence 0-9
    for (i = 0; i < 10; i++)
    {
        UART_Write('0' + i);
        for (j = 0; j < 5000; j++);
    }

    UART_Write('\r');
    UART_Write('\n');

    for (j = 0; j < 20000; j++);

    // Send hex values
    UART_Write('0');
    UART_Write('x');
    for (i = 0; i < 5; i++)
    {
        UART_Write('A' + i);
        for (j = 0; j < 5000; j++);
    }

    UART_Write('\r');
    UART_Write('\n');

    for (j = 0; j < 30000; j++);
}
