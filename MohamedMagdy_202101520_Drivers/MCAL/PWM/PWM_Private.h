#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define CCPR1L      (*(volatile u8*)0x15)
#define CCP1CON     (*(volatile u8*)0x17)

#define T2CON       (*(volatile u8*)0x12)
#define PR2         (*(volatile u8*)0x92)

#ifndef PIR1
#define PIR1        (*(volatile u8*)0x0C)
#endif

#ifndef PIE1
#define PIE1        (*(volatile u8*)0x8C)
#endif

#define DC1B0_BIT   4
#define DC1B1_BIT   5

#define CCP1_PWM_MODE   0x0C

#define TMR2ON_BIT  2

#define T2CKPS_1    0x00
#define T2CKPS_4    0x01
#define T2CKPS_16   0x02

#endif
