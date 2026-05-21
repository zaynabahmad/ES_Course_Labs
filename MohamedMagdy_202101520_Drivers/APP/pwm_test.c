#include "../MCAL/PWM/PWM_Interface.h"
#include "pwm_test.h"

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 30000U; i++) { ; }
}

void PWM_Test(void)
{
    u8 duty;

    PWM_Init();

    PWM_Start();

    for(duty = 0; duty <= 100U; duty += 10U)
    {
        PWM_SetDutyCycle(duty);
        delay();
    }

    PWM_SetDutyCycle(50);
    delay();
    delay();

    for(duty = 100U; duty >= 10U; duty -= 10U)
    {
        PWM_SetDutyCycle(duty);
        delay();
    }
    PWM_SetDutyCycle(0);

    PWM_Stop();
}
