#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Switch reading values */
#define SW_PRESSED      1
#define SW_RELEASED     0

void SW_Init(u8 Port, u8 Pin);
u8 SW_GetState(u8 Port, u8 Pin);

#endif