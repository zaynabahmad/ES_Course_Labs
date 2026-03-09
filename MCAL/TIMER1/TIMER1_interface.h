#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"

void TIMER1_Init(void);
void TIMER1_SetCallBack(void (*LocalPtr)(void));
void TIMER1_ISR_Handler(void);

#endif
