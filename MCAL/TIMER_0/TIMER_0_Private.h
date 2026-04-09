#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TMR0      (*((volatile u8*)0x01))
#define INTCON_T0 (*((volatile u8*)0x0B))
#define OPTION_T0 (*((volatile u8*)0x81))

#define TMR0IE_BIT 5
#define TMR0IF_BIT 2
#define T0CS_BIT   5
#define T0SE_BIT   4
#define PSA_BIT    3

#endif
