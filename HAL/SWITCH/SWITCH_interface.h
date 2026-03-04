#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


#define SWITCH_PRESSED      0
#define SWITCH_NOT_PRESSED  1

void SWITCH_Init(u8 Port, u8 Pin);
u8   SWITCH_GetState(u8 Port, u8 Pin);

#endif