#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Edge Triggering Modes */
#define EXTI_RISING_EDGE    1
#define EXTI_FALLING_EDGE   0

void EXTI_Int0Init(void);
void EXTI_Int0SetEdge(u8 Edge);
void EXTI_Int0SetCallBack(void (*LocalPtr)(void));
void EXTI_ISR_Handler(void);

#endif
