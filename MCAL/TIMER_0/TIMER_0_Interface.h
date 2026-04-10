#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"

void TIMER0_INT(void);
void TIMER0_RESET(void);
void TIMER0_SetCallback(void (*ptr)(void));

#endif