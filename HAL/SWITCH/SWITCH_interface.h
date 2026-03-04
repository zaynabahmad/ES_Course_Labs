#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Switch reading values */
#define SWITCH_PRESSED      0    
#define SWITCH_RELEASED     1

void SWITCH_Init(u8 pin);
u8 SWITCH_GetState(u8 pin);

#endif 