#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void PWM_Init(void);
void PWM_SetDuty(u16 duty);

#endif