#include "app_tests.h"

#include "../MCAL/PWM/PWM_Interface.h"

void APP_Test_PWM(void)
{
    PWM_Init(1000U);
    PWM_SetDutyCycle(50U);
    PWM_Start();
}
