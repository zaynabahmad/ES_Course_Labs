#include "MOTOR_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define MOTOR_IN1_PORT GPIO_PORTD
#define MOTOR_IN1_PIN  GPIO_PIN0

#define MOTOR_IN2_PORT GPIO_PORTD
#define MOTOR_IN2_PIN  GPIO_PIN1


void MOTOR_Init(void)
{
    PWM_Init();

    GPIO_SetPinDirection(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_OUTPUT);

    /* Set motor direction */
    GPIO_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, GPIO_HIGH);
    GPIO_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, GPIO_LOW);
}

void MOTOR_SetSpeed(u8 level_index) {
    switch (level_index) {
        case 0: PWM_SetDuty(125); break;
        case 1: PWM_SetDuty(250); break;
        case 2: PWM_SetDuty(375); break;
        case 3: PWM_SetDuty(498); break;
    }
}