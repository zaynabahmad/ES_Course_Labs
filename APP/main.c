/*
* APPLICATION LAYER
*
*
*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT0_interface.h"

void Toggle_LED_On_Interrupt(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    SWITCH_Init(GPIO_PIN0);

    EXT_INT0_Init();
    EXT_INT0_SetCallback(Toggle_LED_On_Interrupt);

    while(1)
    {
    }
}
