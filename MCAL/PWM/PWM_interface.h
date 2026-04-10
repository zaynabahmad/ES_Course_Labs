#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/Std_Types.h"

/* PWM Mode Selection */
#define PWM_MODE_CCP1   0
#define PWM_MODE_CCP2   1

/* Initialize PWM with specific frequency (in Hz) */
void PWM_Init(u8 pwm_mode, u16 frequency);

/* Set PWM duty cycle (0-100) */
void PWM_SetDutyCycle(u8 pwm_mode, u8 duty_cycle);

/* Enable PWM */
void PWM_Enable(u8 pwm_mode);

/* Disable PWM */
void PWM_Disable(u8 pwm_mode);

#endif
