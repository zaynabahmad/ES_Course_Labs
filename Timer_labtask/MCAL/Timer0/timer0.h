#ifndef TIMER0_H
#define TIMER0_H

#include "../../SERVICES/STD_TYPES.h"

void TIMER0_Init(void);
void TIMER0_Start(void);
void TIMER0_SetCallback(void (*callback)(void));

#endif