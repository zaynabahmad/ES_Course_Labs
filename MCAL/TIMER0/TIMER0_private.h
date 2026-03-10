#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* TMR0 Register */
#define TMR0        (*((volatile u8*)0x01))

/* Shared registers (guarded - may already be defined by EXT_INT0) */
#ifndef OPTION_REG
#define OPTION_REG  (*((volatile u8*)0x81))
#endif

#ifndef INTCON
#define INTCON      (*((volatile u8*)0x0B))
#endif

/* OPTION_REG Bits for Timer0 */
#define PS0     0
#define PS1     1
#define PS2     2
#define PSA     3   /* Prescaler Assignment: 0 = TMR0, 1 = WDT */
#define T0SE    4   /* Timer0 Source Edge Select */
#define T0CS    5   /* Timer0 Clock Source: 0 = Internal (Fosc/4) */

/* INTCON Bits for Timer0 */
#define T0IF    2   /* Timer0 Overflow Interrupt Flag */
#define T0IE    5   /* Timer0 Overflow Interrupt Enable */

/* Shared INTCON bits (guarded) */
#ifndef GIE
#define GIE     7   /* Global Interrupt Enable */
#endif

extern void (*TIMER0_Callback)(void);

#endif
