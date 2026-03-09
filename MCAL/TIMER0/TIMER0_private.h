#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/Std_TYPES.h"

/* Registers */
#define TMR0_REG          (*((volatile u8*)0x01))
#define OPTION_REG_CUSTOM (*((volatile u8*)0x81))
#define INTCON_REG        (*((volatile u8*)0x0B))

/* Interrupt Bits */
#define T0IF_BIT 2
#define T0IE_BIT 5
#define GIE_BIT  7

#endif