#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

void TIMER0_Init(void);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_SetPreload(u8 value);
void TIMER0_SetCallback(void (*ptr)(void));

#endif