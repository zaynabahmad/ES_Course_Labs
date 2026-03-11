#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"


#define OPTION_REG  (*((volatile uint8*)0x81))
#define INTCON      (*((volatile uint8*)0x0B))
#define TMR0        (*((volatile uint8*)0x01))


#define GIE_BIT     7
#define TMR0IE_BIT  5
#define TMR0IF_BIT  2

#define T0CS_BIT    5
#define PSA_BIT     3

#endif