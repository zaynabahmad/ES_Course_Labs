/**
 * @file    app_uart.c
 * @brief   UART echo application -- application layer, no register access.
 *
 * @details A loopback echo is the simplest end-to-end proof of a serial port:
 *          if a typed character comes straight back, the baud solver, the
 *          transmitter and the receiver are all correct. The poll-before-read
 *          keeps the loop responsive instead of blocking on the first call.
 */
#include "app_uart.h"
#include "../MCAL/UART_interface.h"

void vApp_Uart(void)
{
    byte_t u8Echo;

    vUART_Init();
    vUART_SendString("UART ready\r\n");

    while (1)
    {
        /* Only read once the hardware says a byte is genuinely waiting. */
        if (bUART_DataReady() == FLAG_RAISED)
        {
            u8Echo = u8UART_RecvByte();
            vUART_SendByte(u8Echo);
        }
    }
}
