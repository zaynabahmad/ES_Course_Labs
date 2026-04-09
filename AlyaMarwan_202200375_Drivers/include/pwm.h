#ifndef PWM_H
#define PWM_H

#include "std_types.h"
#include "pwm_cfg.h"

void  PWM_Init(void);
void  PWM_SetDuty(uint8 dutyPercent);
void  PWM_Start(void);
void  PWM_Stop(void);

#endif