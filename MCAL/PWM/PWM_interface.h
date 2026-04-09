#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * PWM on CCP1 (pin RC2) using Timer2.
 * Fosc = 4 MHz, Prescaler = 1:4  → PWM freq ≈ 977 Hz (PR2 = 255)
 *
 * Duty cycle range: 0–100 (%)
 */
void PWM_Init(void);
void PWM_SetDuty(u8 duty_percent); /* 0 – 100 */
void PWM_Stop(void);

#endif