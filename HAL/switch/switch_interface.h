#ifndef SWITCH_INTERDFACE_H
#define SWITCH_INTERDFACE_H

#include "../../SERVICES/STD_TYPES.h"

void SWITCH_voidInit(u8 Port, u8 Pin);
u8 SWITCH_u8GetState(u8 Port, u8 Pin);

#endif