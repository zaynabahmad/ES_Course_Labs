#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define CCP1CON  (*((volatile u8*)0x17))
#define CCPR1L   (*((volatile u8*)0x15))
#define T2CON    (*((volatile u8*)0x12))
#define PR2      (*((volatile u8*)0x92))
#define TMR2     (*((volatile u8*)0x11))
#define TRISC    (*((volatile u8*)0x87))

/* CCP1CON bits */
#define CCP1M3  3
#define CCP1M2  2
#define DC1B0   4
#define DC1B1   5

/* T2CON bits */
#define TMR2ON  2
#define T2CKPS0 0
#define T2CKPS1 1

#endif
