#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/std_types.h"

void PWM_voidInit(void);
void PWM_voidSetDutyCycle(u8 copy_u8Duty); // 0 to 100

#endif