#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* PWM Channel IDs */
#define PWM_CHANNEL1    1
#define PWM_CHANNEL2    2

/* PWM Initialization */
void PWM_Init(u8 frequency);

/* Set duty cycle (0-100%) */
void PWM_SetDutyCycle(u8 channel, u8 dutyCycle);

/* Start PWM on specified channel */
void PWM_Start(u8 channel);

/* Stop PWM on specified channel */
void PWM_Stop(u8 channel);

/* Get current duty cycle (0-100%) */
u8 PWM_GetDutyCycle(u8 channel);

#endif
