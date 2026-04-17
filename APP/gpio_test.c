#include "../MCAL/GPIO/GPIO_interface.h"

void GPIO_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_HIGH);

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
}
