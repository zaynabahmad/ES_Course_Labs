#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/std_types.h"

#define EXT_INT_RISING_EDGE   1
#define EXT_INT_FALLING_EDGE  0

void EXT_INT_voidInit(void);
void EXT_INT_voidSetEdge(u8 Copy_u8Edge);
void EXT_INT_voidEnable(void);
void EXT_INT_voidDisable(void);
void EXT_INT_voidSetCallback(void (*Copy_pvCallBackFunc)(void));

#endif