#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/types.h"

#define TMR0_REG        (*((volatile u8*)0x01))
#define OPTION_REG_REG  (*((volatile u8*)0x81))
#define INTCON_REG      (*((volatile u8*)0x0B))

/* Bit definitions */
#define GIE     7
#define T0IE    5
#define T0IF    2

#define PSA     3
#define PS0     0
#define PS1     1
#define PS2     2
#define T0CS    5

#endif