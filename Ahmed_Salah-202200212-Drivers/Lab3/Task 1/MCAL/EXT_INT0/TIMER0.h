#ifndef TIMER0_H
#define TIMER0_H

#include "../../Common/std_types.h"

void TIMER0_Init(void);
void TIMER0_SetCallback(void (*ptr)(void));

#endif