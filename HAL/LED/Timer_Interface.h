#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* HAL functions */
void Timer0_Init(u16 prescaler);
void Timer0_SetDelay(u32 delay_ms, void (*callback)(void));

#endif