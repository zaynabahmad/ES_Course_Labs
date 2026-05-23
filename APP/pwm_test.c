#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\PWM\PWM_interface.h"

void PWM_Test(void)
{
    PWM_voidInit();

    while (1)
    {
        PWM_voidSetDuty(25);
        TIMER0_voidDelayMs(2000);

        PWM_voidSetDuty(50);
        TIMER0_voidDelayMs(2000);

        PWM_voidSetDuty(75);
        TIMER0_voidDelayMs(2000);

        PWM_voidSetDuty(100);
        TIMER0_voidDelayMs(2000);
    }
}