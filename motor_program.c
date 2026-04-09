#include "motor_interface.h"
#include "../../MCAL/PWM/pwm_interface.h"
#include "../../MCAL/GPIO/gpio_interface.h"

#define MOTOR_PIN1_PORT     PORTD_ID
#define MOTOR_PIN1_NUM      PIN0
#define MOTOR_PIN2_PORT     PORTD_ID
#define MOTOR_PIN2_NUM      PIN1

void Motor_Setup(void)
{
    PWM_Setup();
    GPIO_ConfigPin(MOTOR_PIN1_PORT, MOTOR_PIN1_NUM, DIR_OUT);
    GPIO_ConfigPin(MOTOR_PIN2_PORT, MOTOR_PIN2_NUM, DIR_OUT);

    /* Set forward direction */
    GPIO_WritePin(MOTOR_PIN1_PORT, MOTOR_PIN1_NUM, LEVEL_HIGH);
    GPIO_WritePin(MOTOR_PIN2_PORT, MOTOR_PIN2_NUM, LEVEL_LOW);
}

void Motor_SetSpeedLevel(u8 level)
{
    switch(level)
    {
        case 0: PWM_UpdateDuty(256);  break;  /* 25% */
        case 1: PWM_UpdateDuty(512);  break;  /* 50% */
        case 2: PWM_UpdateDuty(768);  break;  /* 75% */
        case 3: PWM_UpdateDuty(1023); break;  /* 100% */
        default: break;
    }
}