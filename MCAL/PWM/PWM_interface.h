#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer2 prescaler options for PWM_PRESCALER in PWM_config.h */
#define PWM_PRESCALER_1    0x00u
#define PWM_PRESCALER_4    0x01u
#define PWM_PRESCALER_16   0x02u

void PWM_Init(void);
void PWM_SetDutyCycle(u8 percent);   /* 0 – 100 */

#endif
