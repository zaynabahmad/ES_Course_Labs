#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TMR0        (*((volatile u8*)0x01))
#define INTCON      (*((volatile u8*)0x0B))
#define OPTION_REG  (*((volatile u8*)0x81))

/* INTCON bits */
#define GIE_BIT     7
#define T0IE_BIT    5
#define T0IF_BIT    2

/* OPTION_REG bits */
#define T0CS_BIT    5
#define PSA_BIT     3
#define PS2_BIT     2
#define PS1_BIT     1
#define PS0_BIT     0

#endif