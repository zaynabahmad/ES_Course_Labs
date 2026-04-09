#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SWITCH States */
#define SWITCH_OFF 0
#define SWITCH_ON 1

void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_Read(u8 Port, u8 Pin);

#endif // !SWITCH_INTERFACE_H
