#include "../MCAL/PWM/PWM_interface.h"

void PWM_Test()
{
    PWM_Init();

    while (1)
    {
        PWM_SetDutyCycle(64);   // low brightness
    }
}