#ifndef MOTOR_H
#define MOTOR_H
#include "../../SERVICES/Std_Types.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/Motor/PWM.h"

/* Assuming Pin 0 and 1 of a port control direction */
void H_Motor_voidInit(u8 copy_u8DirPort, u8 copy_u8Pin1, u8 copy_u8Pin2);
void H_Motor_voidSetSpeed(u8 copy_u8SpeedPercent); // 0 to 100
void H_Motor_voidStop(void);

#endif