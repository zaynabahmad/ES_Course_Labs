#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define EXTI_RISING_EDGE    0
#define EXTI_FALLING_EDGE   1

void EXTI_Init(void);
void EXTI_SetEdge(u8 Edge);
void EXTI_Enable(void);
void EXTI_Disable(void);
void EXTI_SetCallBack(void (*Copy_ptr)(void));

#endif
