#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

// Timer0 initialization function
void TIMER0_Init(void);
// Timer0 start function with specified initial value
void TIMER0_Start(u8 initialValue);
// Timer0 stop function
void TIMER0_Stop(void);
// Timer0 interrupt enable function
void TIMER0_EnableInterrupt(void);
// Timer0 interrupt disable function
void TIMER0_DisableInterrupt(void);
// Timer0 interrupt callback function setter
void TIMER0_SetCallback(void (*LocalFptr)(void));


#endif