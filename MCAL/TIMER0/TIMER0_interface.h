#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/std_types.h"

void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(u8 Copy_u8Preload);
void TIMER0_voidSetCallback(void (*Copy_pvCallBackFunc)(void));

#endif