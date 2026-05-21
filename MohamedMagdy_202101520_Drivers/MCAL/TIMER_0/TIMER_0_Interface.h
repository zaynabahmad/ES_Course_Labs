#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

void TIMER0_Init(void);
void TIMER0_Enable(void);
void TIMER0_Disable(void);
void TIMER0_Reload(void);
u8   TIMER0_GetValue(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
