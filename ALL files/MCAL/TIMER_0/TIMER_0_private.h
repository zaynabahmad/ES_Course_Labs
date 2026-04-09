#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers */
#define TMR0        (*((volatile u8*)0x01))
#define OPTION_REG  (*((volatile u8*)0x81))
#define INTCON      (*((volatile u8*)0x0B))

/* INTCON Bits */
#define GIE     7
#define TMR0IE  5
#define TMR0IF  2

/* OPTION_REG Bits */
#define PSA     3

#endif