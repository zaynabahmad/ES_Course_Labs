#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void TIMER0_Init(void);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetPreload(u8 Preload);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
