#include "GPIO_interface.h"
#include "TIMER0_interface.h"

void TIMER_Test(void)
{
    GPIO_voidSetPinDirection('B',0,0);

    while(1)
    {
        GPIO_voidSetPinValue('B',0,1);
        TIMER0_voidDelay(100);

        GPIO_voidSetPinValue('B',0,0);
        TIMER0_voidDelay(100);
    }
}