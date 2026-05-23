#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"

#define PWM_OK              0u
#define PWM_ERR_INVALID     0xFFu

#define PWM_DUTY_0          0u
#define PWM_DUTY_25         64u
#define PWM_DUTY_50         128u
#define PWM_DUTY_75         191u
#define PWM_DUTY_100        255u

void PWM_voidInit(void);

unsigned char PWM_voidSetDuty(unsigned char duty_percent);

void PWM_voidSetDutyRaw(unsigned char raw);

void PWM_voidStop(void);

#endif /* PWM_INTERFACE_H */