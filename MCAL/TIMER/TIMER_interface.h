#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"

void TIMER_INT(void);
void TIMER_RESET(void);
void TIMER_SetCallback(void (*ptr)(void));
void TIMER_SetCallback2(void (*ptr) (void));



#endif