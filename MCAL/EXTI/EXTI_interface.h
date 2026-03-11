#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(u8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#endif