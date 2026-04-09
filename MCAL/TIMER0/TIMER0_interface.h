#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"

void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(u8 Copy_u8Value);
void TIMER0_voidSetCallback(void (*Copy_ptr)(void));

#endif