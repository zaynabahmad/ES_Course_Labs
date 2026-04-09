#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Definitions for PIC16F877A - Timer0 */

#define TMR0        (*((volatile u8*)0x01))    /* Timer0 counter register */
#define INTCON      (*((volatile u8*)0x0B))    /* Interrupt control register */
#define OPTION_REG  (*((volatile u8*)0x81))    /* Option register (prescaler, clock source) */

/* INTCON bit definitions */
#define T0IE_BIT    5   /* Timer0 Interrupt Enable */
#define T0IF_BIT    2   /* Timer0 Interrupt Flag */
#define GIE_BIT     7   /* Global Interrupt Enable */

/* OPTION_REG bit definitions */
#define PS0_BIT     0   /* Prescaler bits */
#define PS1_BIT     1
#define PS2_BIT     2
#define PSA_BIT     3   /* Prescaler Assignment (0=Timer0, 1=WDT) */
#define T0CS_BIT    4   /* Timer0 Clock Source Select (0=FOSC/4, 1=RA4/T0CKI) */
#define T0SE_BIT    5   /* Timer0 Source Edge Select (0=increment on low-to-high, 1=high-to-low) */

#endif
