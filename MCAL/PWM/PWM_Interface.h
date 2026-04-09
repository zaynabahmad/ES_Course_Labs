#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

/* Channel Select */
#define PWM_CCP1    1
#define PWM_CCP2    2

/* Timer2 Prescaler Options */
#define PWM_T2_PRE_1    0
#define PWM_T2_PRE_4    1
#define PWM_T2_PRE_16   2

void PWM_Init(u8 Channel);
void PWM_Start(u8 Channel);
void PWM_Stop(u8 Channel);
void PWM_SetDuty(u8 Channel, u16 DutyValue);
void PWM_SetDutyPercent(u8 Channel, u8 Percent);

#endif
