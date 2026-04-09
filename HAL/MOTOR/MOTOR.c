#include "MOTOR_interface.h"
#include "MOTOR_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

void MOTOR_Init(void)
{
    GPIO_SetPinDirection(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_LOW);
    PWM_Init();
    PWM_SetDutyCycle(0);
}

void MOTOR_SetDirection(u8 Direction)
{
    if (Direction == MOTOR_CW)
    {
        GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_LOW);
    }
    else
    {
        GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_HIGH);
    }
}

void MOTOR_SetSpeed(u16 SpeedPermille)
{
    PWM_SetDutyCycle(SpeedPermille);
}

void MOTOR_Stop(void)
{
    GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_LOW);
    PWM_SetDutyCycle(0);
}
