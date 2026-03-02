#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* LED States */
#define SWITCH_NOT_PRESSED 0
#define SWITCH_PRESSED     1

void Switch_Init(u8 Port, u8 Pin);
u8 Switch_GetState(u8 Port, u8 Pin);

#endif