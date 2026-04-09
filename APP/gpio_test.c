#include "gpio_test.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void APP_GPIO_Test(void)
{
    /* LED on RA0, Button on RB0 */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    while (1)
    {
        if (GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0) == GPIO_HIGH)
            GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
        else
            GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
    }
}