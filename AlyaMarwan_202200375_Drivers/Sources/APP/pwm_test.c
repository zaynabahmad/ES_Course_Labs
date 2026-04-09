#include "pwm.h"

void PWM_Test(void)
{
    uint8 duty = 0;

    PWM_Init();

    while(1)
    {
        for(duty = 0; duty <= 100; duty++)
        {
            PWM_SetDuty(duty);
            Delay_ms(20);
        }
        for(duty = 100; duty > 0; duty--)
        {
            PWM_SetDuty(duty);
            Delay_ms(20);
        }
    }
}