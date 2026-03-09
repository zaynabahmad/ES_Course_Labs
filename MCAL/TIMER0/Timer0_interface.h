#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void TMR0_Init(void);
void TMR0_Enable(void);
void TMR0_Disable(void);
void TMR0_SetInterval_s(u8 seconds);
void TMR0_SetCallback(void (*ptr)(void));
void TMR0_ISR_Handler(void);




#endif