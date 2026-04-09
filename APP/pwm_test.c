#include "../SERVICES/STD_TYPES.h"
#include "pwm_test.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"

static u8 current_speed = 0;

static void Button_Callback(void)
{
    current_speed = (current_speed + 1) % 4;
    MOTOR_SetSpeed(current_speed);
}

void PWM_TEST_Run(void)
{
    MOTOR_Init();
    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(Button_Callback);
    EXT_INT0_Enable();
    while (1);
}