#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_interface.h"

void GPIO_Test(void)
{
    GPIO_voidSetPinDirection('B', 0, OUTPUT);
    GPIO_voidSetPinDirection('B', 1, OUTPUT);

    while (1)
    {
        GPIO_voidSetPinValue('B', 0, HIGH);
        GPIO_voidSetPinValue('B', 1, LOW);
        TIMER0_voidDelayMs(500);

        GPIO_voidSetPinValue('B', 0, LOW);
        GPIO_voidSetPinValue('B', 1, HIGH);
        TIMER0_voidDelayMs(500);
    }
}