#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void PWM_Init(void);
void PWM_SetDutyCycle(u8 DutyCycle);
void PWM_Stop(void);

#endif