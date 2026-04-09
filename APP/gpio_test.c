#include "../MCAL/GPIO/GPIO_interface.h"
#include "gpio_test.h"

void gpio_test_run(void)
{
    /* Initialize all ports */
    GPIO_Init();

    /* Set PORTB pin0 as output and drive high */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);

    /* Set PORTB pin1 as output and drive low */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);

    /* Set PORTA pin0 as input and read its value */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
    GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN0);

    /* Toggle PORTB pin0 */
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_LOW);
    GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
}
