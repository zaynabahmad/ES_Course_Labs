#include "../MCAL/PWM/PWM_Interface.h"

/* Test: ramp PWM duty on CCP1 (RC2) from 0% to 100% */
void PWM_Test(void)
{
    u8 duty;

    PWM_Init(PWM_CCP1);
    PWM_SetDutyPercent(PWM_CCP1, 0);
    PWM_Start(PWM_CCP1);

    while(1)
    {
        for(duty = 0; duty <= 100; duty += 5)
        {
            PWM_SetDutyPercent(PWM_CCP1, duty);
            { volatile u16 d; for(d=0; d<30000; d++); }
        }
        for(duty = 100; duty > 0; duty -= 5)
        {
            PWM_SetDutyPercent(PWM_CCP1, duty);
            { volatile u16 d; for(d=0; d<30000; d++); }
        }
    }
}
