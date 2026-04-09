#include "../SERVICES/types.h"
#include "pwm_test.h"
#include "../MCAL/EXT_INT/ext_int_interface.h"
#include "../HAL/MOTOR/motor_interface.h"

static volatile u8 speed_index = 0;

static void ButtonPressHandler(void)
{
    speed_index = (speed_index + 1) % 4;
    Motor_SetSpeedLevel(speed_index);
}

void PWM_Test_Runner(void)
{
    Motor_Setup();
    EXTINT_Setup();
    EXTINT_SetTriggerEdge(EDGE_RISING);
    EXTINT_RegisterCallback(ButtonPressHandler);
    EXTINT_Activate();
    while(1);
}