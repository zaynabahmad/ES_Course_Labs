#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

void GPIO_Test(void)
{
    GPIO_Init();
    
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_INPUT);
    
    while(1)
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
        for(u16 i = 0; i < 10000; i++);
        
        LED_Off(GPIO_PORTB, GPIO_PIN0);
        LED_On(GPIO_PORTB, GPIO_PIN1);
        for(u16 i = 0; i < 10000; i++);
        
        LED_Off(GPIO_PORTB, GPIO_PIN1);
        LED_On(GPIO_PORTB, GPIO_PIN2);
        for(u16 i = 0; i < 10000; i++);
        
        LED_Off(GPIO_PORTB, GPIO_PIN2);
        
        u8 button_state = GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN0);
        
        if(button_state == GPIO_HIGH)
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
            LED_On(GPIO_PORTB, GPIO_PIN2);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTB, GPIO_PIN2);
        }
    }
}
