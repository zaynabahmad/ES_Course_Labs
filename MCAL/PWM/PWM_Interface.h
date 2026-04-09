#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


void PWM_voidInit(void);
void PWM_voidSetDutyCycle(u8 Copy_u8DutyPercent);
void PWM_voidSetDutyRaw(u16 Copy_u16DutyValue);
void PWM_voidStart(void);
void PWM_voidStop(void);

#endif /* PWM_INTERFACE_H */