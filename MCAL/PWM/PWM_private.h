#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define CCP1CON   (*((volatile u8*)0x17))
#define CCPR1L    (*((volatile u8*)0x15))
#define T2CON     (*((volatile u8*)0x12))
#define PR2       (*((volatile u8*)0x92))
#define PIR1      (*((volatile u8*)0x0C))

/* Bits */
#define TMR2ON_BIT    2
#define T2CKPS0_BIT   0
#define T2CKPS1_BIT   1
#define TMR2IF_BIT    1

#define CCP1M0_BIT    0
#define CCP1M1_BIT    1
#define CCP1M2_BIT    2
#define CCP1M3_BIT    3
#define DC1B0_BIT     4
#define DC1B1_BIT     5

#endif