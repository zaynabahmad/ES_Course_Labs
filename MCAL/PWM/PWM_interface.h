#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Initializes Timer2 and CCP1 in PWM Mode */
void PWM1_Init(void);

/* Sets the duty cycle from 0 to 100 percent */
void PWM1_SetDutyCycle(uint8 duty_cycle_percent);

#endif /* PWM_INTERFACE_H */