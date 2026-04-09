#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


void PWM1_Init(void);
void PWM1_SetDuty(u8 duty);

#endif