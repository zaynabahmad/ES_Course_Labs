#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "SERVICES\STD_TYPES.h"


void TIMER0_Init(u8 prescaler);

/* Load a preload value to tune overflow period */
void TIMER0_SetPreload(u8 preload);

/* Polling-based blocking delay in milliseconds (approx, Fosc=4MHz) */
void TIMER0_DelayMs(u16 ms);

/* Interrupt-driven interface */
void TIMER0_EnableOverflowInterrupt(void);
void TIMER0_DisableOverflowInterrupt(void);
void TIMER0_SetCallback(void (*Callback)(void));

/* Called from Interrupt_Manager */
void TIMER0_ISR(void);

#endif