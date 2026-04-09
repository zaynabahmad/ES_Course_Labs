/*
 * uart_test.c
 * APP Layer - UART Driver Test
 *
 * Test Description:
 *   - Send greeting message on startup
 *   - Echo received characters back
 *   - Send incrementing counter every second
 */

#include "uart_test.h"
#include "../MCAL/UART/uart.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../SERVICES/services.h"

static u16 g_uartCounter = 0;

void UART_Test_Init(void)
{
    /* 9600 baud, 4MHz Fosc */
    UART_Init(UART_BAUD_9600);
    UART_SendString((u8*)"=== UART Test Started ===\r\n");
    UART_SendString((u8*)"Send any character to echo\r\n");
}

void UART_Test_SendCounter(void)
{
    u8 buf[8];
    UART_SendString((u8*)"Counter: ");
    Utils_UintToStr(g_uartCounter, buf);
    UART_SendString(buf);
    UART_SendString((u8*)"\r\n");
    g_uartCounter++;
}

void UART_Test_Echo(void)
{
    u8 received;
    if(UART_IsDataAvailable())
    {
        received = UART_ReceiveByte();
        UART_SendString((u8*)"Echo: ");
        UART_SendByte(received);
        UART_SendString((u8*)"\r\n");

        /* Check for errors */
        if(UART_GetError() != UART_OK)
        {
            UART_SendString((u8*)"[UART ERROR]\r\n");
        }
    }
}

void UART_Test_Run(void)
{
    UART_Test_Init();

    while(1)
    {
        UART_Test_Echo();
        TIMER0_DelayMs(1000);
        UART_Test_SendCounter();
    }
}
