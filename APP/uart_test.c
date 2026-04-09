#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

void UART_RX_Callback(u8 received_data)
{
    if(received_data == '1')
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
    }
    else if(received_data == '0')
    {
        LED_Off(GPIO_PORTB, GPIO_PIN0);
    }
    
    UART_Write(received_data);
}

void UART_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    
    UART_RX_Init();
    UART_TX_Init();
    
    UART_SetCallback(UART_RX_Callback);
    
    UART_Write('S');
    UART_Write('t');
    UART_Write('a');
    UART_Write('r');
    UART_Write('t');
    UART_Write('\n');
    
    while(1)
    {
    }
}
