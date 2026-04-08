#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

/* Initialize Timer0 with the prescaler and preload defined in config */
void TIMER0_Init(void);

/* Enable Timer0 interrupt and global interrupts */
void TIMER0_Enable(void);

/* Disable Timer0 interrupt */
void TIMER0_Disable(void);

/* Reload TMR0 with the preload value (call inside ISR for periodic ticks) */
void TIMER0_Reload(void);

/* Read the current TMR0 counter value */
u8 TIMER0_GetValue(void);

/* Register the overflow callback function */
void TIMER0_SetCallback(void (*Callback)(void));

/* ISR handler — call from Interrupt_Manager when T0IF is set */
void TIMER0_ISR(void);

#endif