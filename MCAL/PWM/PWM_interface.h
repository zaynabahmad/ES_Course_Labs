#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* PWM Channel Selection */
#define PWM_CHANNEL_1 1
#define PWM_CHANNEL_2 2

/* Function Prototypes */
void PWM_Init(u8 channel);
void PWM_SetDutyCycle(u8 channel, u8 duty_cycle_percent);
void PWM_Start(void);
void PWM_Stop(void);

#endif