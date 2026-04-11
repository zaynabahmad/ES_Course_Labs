#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void PWM_Init(unsigned long freq_hz);
void PWM_Start(void);
void PWM_Stop(void);
void PWM_SetDutyPercent(u8 duty_percent);
void PWM_SetDutyRaw(u8 duty_raw);

#endif