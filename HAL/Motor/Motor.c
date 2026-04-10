#include "../../SERVICES/STD_TYPES.h"

/* MCAL Inclusions */
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h" /* Assuming you named your PWM driver this */

#include "Motor_config.h"
#include "Motor_interface.h"

void Motor_voidInit(void)
{
    /* 1. Set the direction pins as OUTPUT */
    GPIO_SetPinDirection(MOTOR_DIR_PORT, MOTOR_IN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_DIR_PORT, MOTOR_IN2_PIN, GPIO_OUTPUT);

    /* 2. Initialize the motor to be completely stopped safely */
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN1_PIN, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN2_PIN, GPIO_LOW);

    /* 3. Initialize the PWM module for speed control */
    PWM_voidInit();
    PWM_voidSetDutyCycle(0); /* Start at 0% speed */
}

void Motor_voidForward(void)
{
    /* L293D Forward: IN1 = HIGH, IN2 = LOW */
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN1_PIN, GPIO_HIGH);
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN2_PIN, GPIO_LOW);
}

void Motor_voidBackward(void)
{
    /* L293D Backward: IN1 = LOW, IN2 = HIGH */
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN1_PIN, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN2_PIN, GPIO_HIGH);
}

void Motor_voidStop(void)
{
    /* L293D Stop: IN1 = LOW, IN2 = LOW (Fast Motor Stop) */
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN1_PIN, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_DIR_PORT, MOTOR_IN2_PIN, GPIO_LOW);
}

void Motor_voidSetSpeed(u8 Copy_u8SpeedPercentage)
{
    /* Safety check to cap speed at 100% */
    if (Copy_u8SpeedPercentage > 100)
    {
        Copy_u8SpeedPercentage = 100;
    }
    
    /* Pass the requested speed directly to the MCAL PWM driver */
    PWM_voidSetDutyCycle(Copy_u8SpeedPercentage);
}