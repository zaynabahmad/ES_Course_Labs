#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "PWM_Config.h"
#include "PWM_Private.h"

// T2CON
#define TMR2ON 2
#define T2CKPS1 1
#define T2CKPS0 0

// CCP1CON
#define CCPxX 5
#define CCPxY 4
#define CCPxM2_BIT 2
#define CCPxM1_BIT 1

void PWM_Init(void);
void PWM_Enable(void);
void PWM_Disable(void);

void PWM_SetDutyCycle(u16 DutyCycle);
void PWM_SetPeriod(u8 Period);

#endif
