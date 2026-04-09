#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/std_types.h"

/* Prescaler Definitions */
#define TIMER0_PRESCALER_2     0
#define TIMER0_PRESCALER_4     1
#define TIMER0_PRESCALER_8     2
#define TIMER0_PRESCALER_16    3
#define TIMER0_PRESCALER_32    4
#define TIMER0_PRESCALER_64    5
#define TIMER0_PRESCALER_128   6
#define TIMER0_PRESCALER_256   7

void TIMER0_voidInit(u8 copy_u8Prescaler);
void TIMER0_voidSetPreload(u8 copy_u8Preload);
u8   TIMER0_u8GetTimerValue(void);

#endif