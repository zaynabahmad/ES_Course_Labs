#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

#define PWM_CHANNEL_1  1
#define PWM_CHANNEL_2  2

/* Initialize the PWM modules (Sets period and configures Timer2) */
void PWM_Init(void);

/* Start PWM on the specified channel */
void PWM_Start(u8 Channel);

/* Stop PWM on the specified channel */
void PWM_Stop(u8 Channel);

/* * Set the duty cycle (0 to 100 percentage or raw value depending on implementation).
 * This implementation takes a percentage (0 - 100).
 */
void PWM_SetDutyCycle(u8 Channel, u8 DutyPercent);

#endif