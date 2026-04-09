#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

void MOTOR_Init(u8 Port, u8 Pin1, u8 Pin2, u8 PWMChannel)
{
    motor_port = Port;
    motor_pin1 = Pin1;
    motor_pin2 = Pin2;
    motor_pwm_channel = PWMChannel;

    GPIO_SetPinDirection(motor_port, motor_pin1, GPIO_OUTPUT);
    GPIO_SetPinDirection(motor_port, motor_pin2, GPIO_OUTPUT);

    PWM_Init(motor_pwm_channel, 5000); // 5kHz PWM
    MOTOR_Stop();
}

void MOTOR_Forward(u8 Speed)
{
    if (Speed > 100) Speed = 100;
    GPIO_SetPinValue(motor_port, motor_pin1, GPIO_HIGH);
    GPIO_SetPinValue(motor_port, motor_pin2, GPIO_LOW);
    PWM_SetDutyCycle(motor_pwm_channel, Speed);
}

void MOTOR_Stop(void)
{
    GPIO_SetPinValue(motor_port, motor_pin1, GPIO_LOW);
    GPIO_SetPinValue(motor_port, motor_pin2, GPIO_LOW);
    PWM_SetDutyCycle(motor_pwm_channel, 0);
}

void MOTOR_Backward(u8 Speed)
{
    if (Speed > 100) Speed = 100;
    GPIO_SetPinValue(motor_port, motor_pin1, GPIO_LOW);
    GPIO_SetPinValue(motor_port, motor_pin2, GPIO_HIGH);
    PWM_SetDutyCycle(motor_pwm_channel, Speed);
}
