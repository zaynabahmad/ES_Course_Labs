#include "../MCAL/USART/USART_Interface.h"

void UART_Test(void)
{
    u8 ReceivedData;

    /* Initialize UART for transmission */
    UART_TX_Init();

    /* Initialize UART for reception */
    UART_RX_Init();

    /* Test 1: Send a test byte */
    UART_Write(0x41);  /* Send 'A' */

    /* Test 2: Wait and read received data */
    ReceivedData = UART_Read();

    /* Test 3: Check TX status */
    if (UART_TX_Empty())
    {
        /* TX buffer is empty */
    }

    /* Test 4: Set interrupt callback */
    UART_SetCallback(NULL_PTR);
}
