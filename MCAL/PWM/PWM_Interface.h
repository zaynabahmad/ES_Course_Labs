#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

/*
 * Initialize PWM on CCP1 (RC2) using Timer2.
 * Uses default frequency defined in PWM_Config.h.
 */
void PWM_Init(void);

/*
 * Set PWM duty cycle.
 * duty: 0 (0%) to 100 (100%)
 */
void PWM_SetDutyCycle(u8 duty);

/* Start PWM output (enable Timer2) */
void PWM_Start(void);

/* Stop PWM output (disable Timer2, output stays low) */
void PWM_Stop(void);

#endif