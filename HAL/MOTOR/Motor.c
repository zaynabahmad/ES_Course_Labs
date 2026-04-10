#include "Motor.h"
#include "../../MCAL/PWM/PWM_interface.h"

/* Current motor speed state */
static u8 current_speed_index = 0;
static const u8 speed_levels[4] = {25, 50, 75, 100};

void Motor_Init(void) {
    /* Initialize PWM on CCP1 (RC2) with 5kHz frequency */
    PWM_Init(0, 5000);  /* 0 = PWM_MODE_CCP1 */
    PWM_Enable(0);
    /* Start at 25% duty cycle */
    Motor_SetSpeed(MOTOR_DUTY_25);
}

void Motor_SetSpeed(u8 duty_cycle) {
    /* Set PWM duty cycle (0-100) */
    PWM_SetDutyCycle(0, duty_cycle);  /* 0 = PWM_MODE_CCP1 */
}

void Motor_SpeedUp(void) {
    /* Cycle through: 25% -> 50% -> 75% -> 100% -> 25% -> ... */
    current_speed_index = (current_speed_index + 1) % 4;
    Motor_SetSpeed(speed_levels[current_speed_index]);
}

void Motor_Start(void) {
    PWM_Enable(0);
}

void Motor_Stop(void) {
    PWM_Disable(0);
    current_speed_index = 0;
}

u8 Motor_GetCurrentSpeed(void) {
    return speed_levels[current_speed_index];
}
