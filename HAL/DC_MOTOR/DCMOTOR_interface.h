#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void DCMOTOR_Init(u8 Port, u8 Pin1, u8 Pin2);
void DCMOTOR_Forward(u8 Port, u8 Pin1, u8 Pin2);
void DCMOTOR_Reverse(u8 Port, u8 Pin1, u8 Pin2);
void DCMOTOR_Stop(u8 Port, u8 Pin1, u8 Pin2);

#endif