#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer2 Control Register */
#define T2CON    (*((volatile u8*)0x12))

/* PR2 - Period Register */
#define PR2      (*((volatile u8*)0x92))

/* CCP1CON Register */
#define CCP1CON  (*((volatile u8*)0x17))

/* CCPR1L Register */
#define CCPR1L   (*((volatile u8*)0x15))

/* TRISC Register */
#define TRISC    (*((volatile u8*)0x87))

#endif