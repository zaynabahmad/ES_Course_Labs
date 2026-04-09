#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* PWM Channels */
#define PWM_CHANNEL_1  1   // CCP1 ? RC2
#define PWM_CHANNEL_2  2   // CCP2 ? RC1


/*
 * Function: PWM_Init
 * ------------------
 * Initializes PWM module:
 * - Sets Timer2 prescaler
 * - Loads PR2 value
 */
void PWM_Init(void);


/*
 * Function: PWM_Start
 * -------------------
 * Enables PWM on selected channel
 */
void PWM_Start(u8 Channel);


/*
 * Function: PWM_Stop
 * ------------------
 * Disables PWM on selected channel
 */
void PWM_Stop(u8 Channel);


/*
 * Function: PWM_SetDutyCycle
 * --------------------------
 * Sets duty cycle as percentage (0 ? 100)
 */
void PWM_SetDutyCycle(u8 Channel, u8 DutyPercent);

#endif