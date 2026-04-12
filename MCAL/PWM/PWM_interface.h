#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* PWM Channels */
#define PWM_CHANNEL1 0 /* CCP1 on RC2 */
#define PWM_CHANNEL2 1 /* CCP2 on RC1 */

/* Duty Cycle */
#define PWM_DUTY_MIN 0
#define PWM_DUTY_MAX 100

/* Function Prototypes */
void PWM_Init(void);
void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle);
u8 PWM_GetDutyCycle(u8 Channel);
void PWM_Start(u8 Channel);
void PWM_Stop(u8 Channel);
void PWM_SetFrequency(u16 FrequencyHz);

#endif
