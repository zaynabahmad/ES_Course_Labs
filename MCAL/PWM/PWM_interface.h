#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* APIs */
void PWM_Init(void);
void PWM_SetDutyCycle(u16 duty);

#endif