#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Channel Definitions */
#define PWM_CCP1    1
#define PWM_CCP2    2

void PWM_Init(void);
void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle_Percent);
void PWM_Start(u8 Channel);
void PWM_Stop(u8 Channel);

#endif
