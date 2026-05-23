#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\TIMER0\TIMER0_interface.h"

void TIMER_Test(void)
{
    GPIO_voidSetPinDirection('B', 0, OUTPUT);
    GPIO_voidSetPinDirection('B', 1, OUTPUT);

    TIMER0_voidInit();

    while (1)
    {
        GPIO_voidTogglePin('B', 0);
        TIMER0_voidDelayMs(100);

        GPIO_voidTogglePin('B', 1);
        TIMER0_voidDelayMs(100);
    }
}