#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/UART/uart_interface.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void app_uart_test(void)
{
    u8 receivedChar;

    UART_Init();

    while(1)
    {
        receivedChar = UART_ReceiveChar();
        UART_SendChar(receivedChar);
    }
}