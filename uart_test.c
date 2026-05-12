#include "uart_test.h"
#include "../MCAL/UART_INTERFACE.h"

static u8 msg[] = "Hello from PIC\r\n";

void UART_Test_Init(void)
{
    UART_Init();
}

void UART_Test_Run(void)
{
    u8 rx_byte;

    /* Send greeting message */
    UART_SendString(msg);

    /* Echo any received byte back */
    if(UART_IsDataAvailable())
    {
        rx_byte = UART_ReceiveByte();
        UART_SendByte(rx_byte);
    }
}
