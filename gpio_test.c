#include "gpio_test.h"
#include "../MCAL/GPIO_INTERFACE.h"

void GPIO_Test_Init(void)
{
    /* PORTA pin0 as output (LED), PORTB pin0 as input (button) */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
}

void GPIO_Test_Run(void)
{
    /* Mirror the state of the input button onto the output LED */
    u8 state = GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN0);
    GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, state);
}
