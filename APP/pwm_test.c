#include "../MCAL/PWM/PWM_interface.h"

void PWM_Test(void)
{
    /* Initialize PWM */
    PWM_Init();

    /* Set duty cycle to 50% */
    PWM_SetDutyCycle(50);
}