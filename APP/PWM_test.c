#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"


static u8 Global_u8SpeedLevel = 0;

static void App_ChangeSpeed(void)
{
    Global_u8SpeedLevel++;
    if(Global_u8SpeedLevel > 3)
    {
        Global_u8SpeedLevel = 0;
    }

    switch(Global_u8SpeedLevel)
    {
        case 0: PWM_SetDutyCycle(25);  break;
        case 1: PWM_SetDutyCycle(50);  break;
        case 2: PWM_SetDutyCycle(75);  break;
        case 3: PWM_SetDutyCycle(100); break;
    }
}

void APP_voidPWMTest(void)
{
    PWM_Init(249);

    EXT_INT_Init();
    EXT_INT_SetCallback(App_ChangeSpeed);

    SET_BIT(INTCON, 7);
    PWM_SetDutyCycle(25);

    while(1)
    {
    }
}