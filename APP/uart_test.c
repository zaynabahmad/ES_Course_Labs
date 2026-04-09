#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Callback: echo received byte back */
void UART_RX_Callback(u8 data)
{
    UART_Write(data);
}

/* Test: UART echo — send back whatever is received */
void UART_Test(void)
{
    UART_TX_Init();
    UART_RX_Init();
    UART_SetCallback(UART_RX_Callback);

    /* Send a greeting */
    UART_WriteString("UART Ready\r\n");

    while(1)
    {
        /* RX handled by interrupt */
    }
}
