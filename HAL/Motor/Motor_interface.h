#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Initialization */
void Motor_voidInit(void);

/* Direction Control */
void Motor_voidForward(void);
void Motor_voidBackward(void);
void Motor_voidStop(void);

/* Speed Control (0 to 100 percent) */
void Motor_voidSetSpeed(u8 Copy_u8SpeedPercentage);

#endif /* MOTOR_INTERFACE_H */