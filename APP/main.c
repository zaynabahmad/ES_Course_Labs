/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void ButtonPressedCallback(void)
{
   
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}

void main()
{
    EXT_INT0_Init();
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    EXT_INT0_Enable();
    EXT_INT0_SetCallback(ButtonPressedCallback);


    while(1)
    {

    }
}