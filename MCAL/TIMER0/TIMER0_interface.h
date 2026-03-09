#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"

void TIMER0_Init(void);
void TIMER0_SetCallBack(void (*LocalPtr)(void));
void TIMER0_ISR_Handler(void);

#endif
