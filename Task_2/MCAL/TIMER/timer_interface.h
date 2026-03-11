#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../SERVICES/std_types.h"

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 preload);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_ISR_Handler(void);
#endif