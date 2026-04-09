#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define EXT_INT_RISING_EDGE  1
#define EXT_INT_FALLING_EDGE 0

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 EdgeType);
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);

#endif
