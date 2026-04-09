#include "app_tests.h"

#include "../MCAL/GPIO/GPIO_interface.h"

void APP_Test_GPIO(void)
{
    GPIO_Init();
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTC, GPIO_PIN0, GPIO_HIGH);
}
