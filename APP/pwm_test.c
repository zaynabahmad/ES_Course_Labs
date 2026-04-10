#include "APP_Tests.h"
#include "../MCAL/PWM/PWM_Interface.h"

void APP_Test_PWM(void)
{
    PWM1_Init();
    while(1)
    {
        // Set duty cycle to 50%
        PWM1_SetDutyCycle(50);
    }
}
