#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/PWM/PWM_interface.h"

/* Motor States */
#define MOTOR_FORWARD  1
#define MOTOR_STOP     0
#define MOTOR_BACKWARD 2

/* Motor Speed (0-100%) */
#define MOTOR_SPEED_MIN    0
#define MOTOR_SPEED_MAX    100

void MOTOR_Init(u8 Port, u8 Pin1, u8 Pin2, u8 PWMChannel);
void MOTOR_Forward(u8 Speed);
void MOTOR_Stop(void);
void MOTOR_Backward(u8 Speed);

#endif