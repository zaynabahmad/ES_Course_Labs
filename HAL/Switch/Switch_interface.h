#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"
/********** Configuration **********/
void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_Read(u8 Port, u8 Pin);

#endif