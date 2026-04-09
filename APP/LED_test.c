#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "LED_test.h"


void LED_Test(void)
{

    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN2, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN3, GPIO_INPUT);

    while(1)
    {
        if(GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN2))
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
        }
        else if(GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN3))
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN0);
            LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
        }
    }
}