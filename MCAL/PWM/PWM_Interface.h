#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

typedef struct
{
    u8 Period;
    u8 DutyPercent;
    u8 Timer2Prescaler;
} PWM_ConfigType;

void PWM_Init(PWM_ConfigType *ConfigPtr);
void PWM_Start(void);
void PWM_Stop(void);
void PWM_SetDutyCycle(u8 DutyPercent);

#endif
