#ifndef EXT_interface_H
#define EXT_interface_H

#include "STD_TYPES.h"

#define EXT_INT0_RISING_EDGE   1
#define EXT_INT0_FALLING_EDGE  0

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(uint8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));

#endif