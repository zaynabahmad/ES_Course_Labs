#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

#define PWM_CHANNEL_1  0
#define PWM_CHANNEL_2  1

void PWM_Init(u8 Channel);
void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle);
void PWM_Start(u8 Channel);
void PWM_Stop(u8 Channel);

#endif
