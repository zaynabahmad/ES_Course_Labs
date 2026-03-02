#ifndef HAL_SWITCH_SWITCH_H_
#define HAL_SWITCH_SWITCH_H_

#include "../../SERVICES/STD_TYPES.h"
void SWITCH_Init(u8 Port, u8 Pin);
u8 SWITCH_Read(u8 Port, u8 Pin);

#endif