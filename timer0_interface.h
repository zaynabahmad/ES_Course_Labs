#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/types.h"

void Timer0_Configure(void);
void Timer0_Run(void);
void Timer0_Halt(void);
void Timer0_LoadCounter(u8 value);
void Timer0_AttachCallback(void (*cb)(void));

#endif