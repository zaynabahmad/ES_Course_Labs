#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#include "D:\Timer-week3\Services\STD_TYPES.h"

void TIMER0_Init(void);
void TIMER0_SetCallback_1Sec(void (*ptr)(void));
void TIMER0_SetCallback_2Sec(void (*ptr)(void));

#endif