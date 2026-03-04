#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"




void BUTTON_Init(u8 Port, u8 Pin);
u8 BUTTON_GetState(u8 Port , u8 Pin);

#endif