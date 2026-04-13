#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define CCP1CON   (*((volatile u8*)0x17))
#define CCP2CON   (*((volatile u8*)0x1D))
#define CCPR1L    (*((volatile u8*)0x15))
#define CCPR2L    (*((volatile u8*)0x1C))
#define PWM1CON   (*((volatile u8*)0x9B))
#define TMR2      (*((volatile u8*)0x11))
#define PR2       (*((volatile u8*)0x92))
#define T2CON     (*((volatile u8*)0x12))
#define TRISC     (*((volatile u8*)0x87))
#define PORTC     (*((volatile u8*)0x07))

#define CCP_MODE_PWM  0x0C
#define CCP_MODE_OFF  0x00

#define TMR2ON    2
#define T2CKPS1   1
#define T2CKPS0   0

#define T2_PRESCALER_1   0
#define T2_PRESCALER_4   1
#define T2_PRESCALER_16  2

#endif
