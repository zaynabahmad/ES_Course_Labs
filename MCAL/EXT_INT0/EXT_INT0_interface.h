#ifndef EXT_INT0_INTERFACE_H
#define EXT_INT0_INTERFACE_H

#include "STD_TYPES.h"

#define EXT_INT0_RISING_EDGE   1
#define EXT_INT0_FALLING_EDGE  0

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(u8 Copy_u8Edge);
void EXT_INT0_SetCallback(void (*Copy_ptr)(void));

#endif