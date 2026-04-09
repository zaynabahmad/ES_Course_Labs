#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void SWITCH_Init(u8 Port, u8 Pin);
u8   SWITCH_GetState(u8 Port, u8 Pin);

#endif