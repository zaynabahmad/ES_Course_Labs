#include "pwm_test.h"
#include "../MCAL/PWM_INTERFACE.h"

static u8 duty = 0;
static u8 direction = 1; /* 1=increasing, 0=decreasing */

void PWM_Test_Init(void)
{
    PWM_Init();
    PWM_SetDutyCycle(0);
}

void PWM_Test_Run(void)
{
    /* Ramp duty cycle up and down between 0% and 100% */
    PWM_SetDutyCycle(duty);

    if(direction == 1)
    {
        if(duty < 100)
            duty++;
        else
            direction = 0;
    }
    else
    {
        if(duty > 0)
            duty--;
        else
            direction = 1;
    }
}
