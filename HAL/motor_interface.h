#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

#include "D:/ES-Project-Lab/SERVICES/std_types.h"

void MOTOR_Init(u8 port1, u8 pin1, u8 port2, u8 pin2);
void MOTOR_Forward(u8 port1, u8 pin1, u8 port2, u8 pin2);
void MOTOR_Reverse(u8 port1, u8 pin1, u8 port2, u8 pin2);
void MOTOR_Stop(u8 port1, u8 pin1, u8 port2, u8 pin2);

#endif