#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_Config.h"
#include "PWM_Private.h"

/* ================= Channel Macros ================= */

#define PWM_CHANNEL_1    1
#define PWM_CHANNEL_2    2

/* ================= Prescaler Macros ================= */

#define PWM_PRESCALER_1     0x00
#define PWM_PRESCALER_4     0x01
#define PWM_PRESCALER_16    0x02

/* ================= Function Prototypes ================= */

void PWM_Init(u8 Channel);
void PWM_SetDutyCycle(u8 Channel, u8 DutyCycle);   /* DutyCycle: 0-100 */
void PWM_Start(u8 Channel);
void PWM_Stop(u8 Channel);

#endif
