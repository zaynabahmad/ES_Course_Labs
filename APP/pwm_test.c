#include "PWM_interface.h"

void PWM_Test(void)
{
    PWM_voidInit();

    while(1)
    {
        PWM_voidSetDuty(128); // 50% duty
    }
}