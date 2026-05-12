#include "led_test.h"
#include "../HAL/LED_INTERFACE.h"
#include "../MCAL/GPIO_INTERFACE.h"

void LED_Test_Init(void)
{
    LED_Init(GPIO_PORTC, GPIO_PIN0);
}

void LED_Test_Run(void)
{
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}
