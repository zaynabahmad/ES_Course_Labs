#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void PWM_Init(u16 FrequencyHz);
void PWM_Start(void);
void PWM_Stop(void);
void PWM_SetDutyCycle(u8 DutyPercent);

#endif
