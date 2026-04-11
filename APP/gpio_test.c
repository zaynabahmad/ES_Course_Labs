#include "../MCAL/GPIO/GPIO_interface.h"

void APP_GPIO_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);

    while(1)
    {
        if(GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0) == GPIO_HIGH)
        {
            GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_HIGH);
        }
        else
        {
            GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);
        }
    }
}