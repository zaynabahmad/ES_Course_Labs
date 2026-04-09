#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/types.h"

void PWM_Setup(void);
void PWM_UpdateDuty(u16 duty_cycle);

#endif