#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

void PWM_Init(void);
void PWM_SetDutyCycle(u8 DutyCyclePercent);
void PWM_Stop(void);

#endif
