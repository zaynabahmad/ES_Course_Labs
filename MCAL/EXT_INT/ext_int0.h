#ifndef EXT_INT0_H
#define EXT_INT0_H

#define EXT_INT0_RISING_EDGE    1
#define EXT_INT0_FALLING_EDGE   0

#include "../../SERVICES/STD_TYPES.h"

void EXT_INT0_Init(void);
void EXT_INT0_SetEdge(u8 Edge);
void EXT_INT0_SetCallback(void (*LocalFptr)(void));
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);





#endif