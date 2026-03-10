#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Initializes Timer0 based on the settings in TIMER0_config.h */
void TIMER0_voidInit(void);

/* Sets a new starting value in the TMR0 register */
void TIMER0_voidSetPreload(u8 Copy_u8PreloadValue);

/* Enables the Timer0 Overflow Interrupt */
void TIMER0_voidEnableInterrupt(void);

/* Disables the Timer0 Overflow Interrupt */
void TIMER0_voidDisableInterrupt(void);

#endif