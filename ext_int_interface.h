#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/types.h"

#define EDGE_RISING     1
#define EDGE_FALLING    0

void EXTINT_Setup(void);
void EXTINT_Activate(void);
void EXTINT_Deactivate(void);
void EXTINT_SetTriggerEdge(u8 edge);
void EXTINT_RegisterCallback(void (*callback)(void));
void EXTINT_ClearFlag(void);

#endif