#include "EXTI_interface.h"
#include "GPIO_interface.h"

void interrupt ISR(void)
{
    GPIO_TogglePin(GPIO_PORTB, GPIO_PIN1);
}

void test_EXTI(void)
{
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);

    EXTI_Init(EXTI_RISING_EDGE);
    EXTI_Enable();

    while (1);   /* wait for interrupts */
}