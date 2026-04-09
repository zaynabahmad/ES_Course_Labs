#include "app_tests.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void APP_GPIO_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    LED_On(GPIO_PORTC, GPIO_PIN0);
    LED_Toggle(GPIO_PORTC, GPIO_PIN0);
}

