/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/Switch/SWITCH_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN1);

    while(1)
    {
        if(SWITCH_GetState(GPIO_PORTB, GPIO_PIN1) == SWITCH_PRESSED)
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
        }
        
        delay();
    }
}