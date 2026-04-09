#include "pwm_test.h"
#include "../MCAL/PWM/PWM_interface.h"

void PWM_Test(void)
{
    unsigned int duty = 0;

    PWM_Init();

    while(1)
    {
        PWM_SetDuty(duty);
        duty += 10;

        if(duty > 1023)
            duty = 0;

        Delay_ms(100);
    }
}