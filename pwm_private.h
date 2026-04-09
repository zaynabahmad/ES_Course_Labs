#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/types.h"

#define CCP1CON_REG     (*((volatile u8*)0x17))
#define CCPR1L_REG      (*((volatile u8*)0x15))
#define T2CON_REG       (*((volatile u8*)0x12))
#define PR2_REG         (*((volatile u8*)0x92))
#define TRISC_REG       (*((volatile u8*)0x87))

#endif