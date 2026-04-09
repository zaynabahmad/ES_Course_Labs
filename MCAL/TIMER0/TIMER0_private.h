#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer0 Hardware Registers */
#define TMR0        (*((volatile uint8*)0x01))
#define OPTION_REG  (*((volatile uint8*)0x81))
#define INTCON      (*((volatile uint8*)0x0B))

/* OPTION_REG Bits */
#define T0CS_BIT    5   /* Timer0 Clock Source Select bit */
#define T0SE_BIT    4   /* Timer0 Source Edge Select bit */
#define PSA_BIT     3   /* Prescaler Assignment bit */

/* INTCON Bits */
#define GIE_BIT     7   /* Global Interrupt Enable bit */
#define TMR0IE_BIT  5   /* Timer0 Overflow Interrupt Enable bit */
#define TMR0IF_BIT  2   /* Timer0 Overflow Interrupt Flag bit */

#endif