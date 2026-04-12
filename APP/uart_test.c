#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/USART/USART_Interface.h"

static void UART_UserCallback(u8 ReceivedByte)
{
    /* Echo runs in main context via UART_ServiceRx */
    UART_Write(ReceivedByte);
}

void UART_Test(void)
{
    u16 i;

    /* Initialize UART TX and RX */
    UART_TX_Init();
    UART_RX_Init();

    /* Send a test message */
    UART_Write('U');
    UART_Write('A');
    UART_Write('R');
    UART_Write('T');
    UART_Write('_');
    UART_Write('O');
    UART_Write('K');
    UART_Write('\n');

    /* Set callback for interrupt-driven receive */
    UART_SetCallback(UART_UserCallback);

    /* Move RX bytes out of IRQ and invoke callback in main */
    for(i = 0; i < 50000u; i++)
        UART_ServiceRx();
}
