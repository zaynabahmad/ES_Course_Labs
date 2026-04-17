#include "../MCAL/PWM/PWM_Interface.h"

void PWM_Test(void)
{
    PWM_Init();
    PWM_SetDutyCycle(50);   /* 50% duty cycle */
}
