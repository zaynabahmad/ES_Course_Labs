#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


void TMR0_voidInit(void);

void TMR0_voidEnableInterrupt(void);


void TMR0_voidDisableInterrupt(void);


void TMR0_voidSetTimerValue(u8 Copy_u8Value);

u8 TMR0_u8GetTimerValue(void);

void TMR0_voidSetCallback(void (*pvCallBackFunc)(void));

#endif /* TIMER0_INTERFACE_H */