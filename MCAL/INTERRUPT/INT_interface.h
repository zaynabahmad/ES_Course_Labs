#ifndef INT_INTERFACE_H
#define INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define RISING_EDGE  1
#define FALLING_EDGE 0

void EXT_INT_Init(u8 Edge);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetCallback(void (*Callback)(void));

#endif