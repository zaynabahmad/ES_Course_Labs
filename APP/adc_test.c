#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

void ADC_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
    
    ADC_Init();
    
    UART_TX_Init();
    
    u16 adc_value = 0;
    
    while(1)
    {
        adc_value = ADC_Read(ADC_CHANNEL_0);
        
        if(adc_value > 512)
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
        }
        
        UART_Write((u8)(adc_value >> 8));
        UART_Write((u8)(adc_value & 0xFF));
        
        for(u32 i = 0; i < 30000; i++);
    }
}
