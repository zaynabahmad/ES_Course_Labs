#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TRISC       (*((volatile u8*)0x87))

#define CCPR1L      (*((volatile u8*)0x15))
#define CCP1CON     (*((volatile u8*)0x17))
#define T2CON       (*((volatile u8*)0x12))
#define PR2         (*((volatile u8*)0x92))

#define CCP1M0_BIT  0
#define CCP1X_BIT   4
#define TMR2ON_BIT  2

#endif
