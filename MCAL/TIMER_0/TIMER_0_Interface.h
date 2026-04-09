#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 Value);
u8   TIMER0_GetCount(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
