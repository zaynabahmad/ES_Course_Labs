#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers */
#define TMR0        (*((volatile u8*)0x01))
#define OPTION_REG  (*((volatile u8*)0x81))
#define INTCON      (*((volatile u8*)0x0B))

/* OPTION_REG Bits */
#define T0CS_BIT    5   
#define T0SE_BIT    4  
#define PSA_BIT     3   
#define PS2_BIT     2
#define PS1_BIT     1
#define PS0_BIT     0

/* INTCON Bits */
#define GIE_BIT     7
#define T0IE_BIT    5  
#define T0IF_BIT    2   

#endif
