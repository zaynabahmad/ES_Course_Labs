#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_config.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

void MOTOR_Init(void)
{
    /* Set direction pins: IN1=HIGH, IN2=LOW → forward */
    GPIO_SetPinDirection(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_HIGH);
    GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_LOW);

    /* Start PWM at initial duty cycle (25%) */
    PWM_Init();
}

void MOTOR_SetSpeed(u8 duty_percent)
{
    PWM_SetDutyCycle(duty_percent);
}
