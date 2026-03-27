#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer0 Modes */
#define TIMER0_TIMER_MODE       0
#define TIMER0_COUNTER_MODE     1

/* Prescaler Values */
#define TIMER0_PRESCALER_2      0
#define TIMER0_PRESCALER_4      1
#define TIMER0_PRESCALER_8      2
#define TIMER0_PRESCALER_16     3
#define TIMER0_PRESCALER_32     4
#define TIMER0_PRESCALER_64     5
#define TIMER0_PRESCALER_128    6
#define TIMER0_PRESCALER_256    7

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 Value);
u8 TIMER0_GetCount(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
