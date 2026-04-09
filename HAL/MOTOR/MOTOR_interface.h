#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Direction constants */
#define MOTOR_CW    0   /* Clockwise */
#define MOTOR_CCW   1   /* Counter-clockwise */

void MOTOR_Init(void);
void MOTOR_SetDirection(u8 Direction);
void MOTOR_SetSpeed(u16 SpeedPermille);   /* 0–1000 per-mille */
void MOTOR_Stop(void);

#endif
