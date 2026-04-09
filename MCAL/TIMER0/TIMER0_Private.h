#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers */
#define TMR0        (*((volatile u8*)0x01))
#define OPTION_REG  (*((volatile u8*)0x81))
#define INTCON      (*((volatile u8*)0x0B))

/* OPTION_REG Bits */
#define T0CS_BIT    5   /* Clock Source: 0=Internal(Fosc/4), 1=T0CKI pin */
#define T0SE_BIT    4   /* Source Edge: 0=Rising, 1=Falling */
#define PSA_BIT     3   /* Prescaler Assignment: 0=TMR0, 1=WDT */
#define PS2_BIT     2
#define PS1_BIT     1
#define PS0_BIT     0

/* INTCON Bits */
#define GIE_BIT     7
#define T0IE_BIT    5   /* TMR0 Overflow Interrupt Enable */
#define T0IF_BIT    2   /* TMR0 Overflow Interrupt Flag */

#endif
