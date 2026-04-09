#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define TMR0IF   2   /* INTCON: Timer0 Overflow Interrupt Flag bit */
#define TMR0IE  5   /* INTCON: Timer0 Overflow Interrupt Enable bit */

/* Functions matched to the lab skeleton */
void Timer0_Init(void);
void Timer0_EnableInterrupt(void);
void Timer0_Reset(void); 

void Timer0_DisableInterrupt(void);
void TIMER0_ISR(void);
void Timer0_SetCallback(void (*ptr)(void));
void Timer0_EnableGlobalInterrupts(void);


#endif