#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* API Functions */
void PWM_voidInit(void);
void PWM_voidSetDutyCycle(u8 Copy_u8DutyCyclePercent);
void PWM_voidStop(void);

#endif /* PWM_INTERFACE_H */