#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Configuration Macros used in config.h */
#define TIMER0_TIMER_MODE             0
#define TIMER0_COUNTER_MODE           1
#define PRESCALER_ASSIGNED_TO_TIMER0  0
#define PRESCALER_ASSIGNED_TO_WDT     1

/* Core Functions */
void TIMER0_Init(void);
void TIMER0_SetPreload(uint8 value);

/* Interrupt Functions */
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);

/* Callback Function for the ISR */
void TIMER0_SetCallback(void (*ptr_to_func)(void));

#endif