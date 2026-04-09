#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Addresses */
#define TMR0        (*((volatile u8*)0x01))
#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))

/* OPTION_REG bits */
#define T0CS_BIT    5   /* Clock source: 0=internal Fosc/4, 1=T0CKI pin */
#define T0SE_BIT    4   /* Source edge: 0=rising, 1=falling */
#define PSA_BIT     3   /* Prescaler assign: 0=TMR0, 1=WDT */
#define PS2_BIT     2
#define PS1_BIT     1
#define PS0_BIT     0

/* INTCON bits */
#define GIE_BIT     7
#define TMR0IE_BIT  5
#define TMR0IF_BIT  2

#endif
