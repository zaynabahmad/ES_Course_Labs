#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


#define CCP1CON_REG   (*((volatile u8*)0x17))
#define CCPR1L_REG    (*((volatile u8*)0x15))
#define T2CON_REG     (*((volatile u8*)0x12))
#define PR2_REG       (*((volatile u8*)0x92))

// Bits
#define TMR2ON_BIT 2

#endif