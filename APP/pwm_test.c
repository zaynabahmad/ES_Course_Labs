#include "app_tests.h"
#include "../MCAL/PWM/PWM_Interface.h"

static PWM_ConfigType APP_PWM_Config = {249, 50, 1};

void APP_PWM_Test(void)
{
    PWM_Init(&APP_PWM_Config);
    PWM_Start();
    PWM_SetDutyCycle(60);
}
