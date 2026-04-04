/*
 * uart_test.c
 * Tests the UART MCAL driver: TX init, send a string, RX init with
 * interrupt-driven receive and echo-back callback.
 * No direct register access — uses only USART_Interface.h API.
 */

#include "../MCAL/USART/USART_Interface.h"
#include "uart_test.h"

/* Callback: echo every received byte back to the sender */
static void UART_Echo_Callback(u8 received_byte)
{
    UART_Write(received_byte);
}

static void UART_SendString(const char *str)
{
    while(*str != '\0')
    {
        UART_Write((u8)*str);
        str++;
    }
}

void UART_Test(void)
{
    /* Initialise UART transmitter */
    UART_TX_Init();

    /* Send a greeting to confirm TX works */
    UART_SendString("UART Test Start\r\n");

    /* Confirm TX buffer is empty before continuing */
    while(!UART_TX_Empty()) { ; }

    /* Initialise UART receiver with interrupt support */
    UART_RX_Init();

    /* Register echo callback — every received byte is echoed back */
    UART_SetCallback(UART_Echo_Callback);

    UART_SendString("Echo mode active. Type to echo.\r\n");

    /*
     * The test function returns; RX interrupt fires on each received byte.
     * main() keeps the MCU alive in a while(1) loop.
     */
}