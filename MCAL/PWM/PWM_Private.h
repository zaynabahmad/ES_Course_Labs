#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define CCP1CON (*((volatile u8*)0x17))
#define CCPR1L  (*((volatile u8*)0x15))
#define PR2     (*((volatile u8*)0x92))
#define T2CON   (*((volatile u8*)0x12))

#define TMR2ON_BIT 2

#endif
