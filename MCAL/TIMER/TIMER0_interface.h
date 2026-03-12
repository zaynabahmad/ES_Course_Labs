#ifndef TIMER0_H
#define TIMER0_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_private.h"

void Timer0_initialize(void);
void Timer0_Enable(void);
void Timer0_Disable(void);
void TMR0_SetCallback(void (*ptr)(void));
void Timer0_Reset(void);
void Timer0_Set(u8 value);
u8 Timer0_get_flag(void);
void Timer0_set_flag(void);
void Timer0_clr_flag(void);

#endif
