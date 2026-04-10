#ifndef TIMER0_H
#define TIMER0_H
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
void Timer0_initialize(void);

void Timer0_Enable(void);

void Timer0_Disable(void);

void TMR0_SetCallback(void (*ptr)(void));
void Timer0_Reset();
void TImer0_Set(u8 value);
u8 Tmr_get_flag();
void Tmr_set_flag();
void Tmr_clr_flag();
#endif