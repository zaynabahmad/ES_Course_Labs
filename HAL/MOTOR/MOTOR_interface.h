#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Speed presets matching the lab duty cycle levels */
#define MOTOR_SPEED_25     25u
#define MOTOR_SPEED_50     50u
#define MOTOR_SPEED_75     75u
#define MOTOR_SPEED_100    100u

void MOTOR_Init(void);
void MOTOR_SetSpeed(u8 duty_percent);   /* use MOTOR_SPEED_xx constants */

#endif
