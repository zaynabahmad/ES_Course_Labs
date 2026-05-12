#include "switch_test.h"
#include "../HAL/SWITCH_INTERFACE.h"
#include "../HAL/LED_INTERFACE.h"
#include "../MCAL/GPIO_INTERFACE.h"

void SWITCH_Test_Init(void)
{
    switchInit(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTC, GPIO_PIN3);
}

void SWITCH_Test_Run(void)
{
    u8 pressed = switchGetState(GPIO_PORTB, GPIO_PIN1);

    if(pressed == GPIO_HIGH)
        LED_On(GPIO_PORTC, GPIO_PIN3);
    else
        LED_Off(GPIO_PORTC, GPIO_PIN3);
}
