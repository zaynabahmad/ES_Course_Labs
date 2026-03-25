#ifndef EXT_INT0_H
#define EXT_INT0_H

#include "../../Common/std_types.h"

#define EXT_INT0_FALLING_EDGE 0
#define EXT_INT0_RISING_EDGE  1

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(uint8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));

#endif