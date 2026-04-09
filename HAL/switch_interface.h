#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H
#include "D:/ES-Project-Lab/SERVICES/std_types.h"

void SWITCH_Init(u8 port, u8 pin);
u8 SWITCH_GetState(u8 port, u8 pin);

#endif