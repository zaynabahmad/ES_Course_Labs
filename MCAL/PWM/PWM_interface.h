#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * PWM output: CCP1 pin = RC2
 * Duty cycle: 0–1000 (per-mille, i.e. 0 = 0%, 1000 = 100%)
 */

void PWM_Init(void);
void PWM_SetDutyCycle(u16 DutyCycle);
void PWM_Stop(void);

#endif
