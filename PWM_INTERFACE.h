#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

/* Timer2 prescaler options */
#define PWM_PRESCALE_1    0x00
#define PWM_PRESCALE_4    0x01
#define PWM_PRESCALE_16   0x02

void PWM_Init(void);
void PWM_SetDutyCycle(u8 duty_percent);
void PWM_Start(void);
void PWM_Stop(void);

#endif
