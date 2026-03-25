#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"



void Motor_Init(void );
void ForwardMotor(unsigned char speed );
void BackwardMotor(unsigned char speed);
void StopMotor(void);
void BrakeMotor(void);

#endif