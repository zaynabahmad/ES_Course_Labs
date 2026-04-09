#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP1CON (*((volatile u8*)0x17))
#define CCPR1L  (*((volatile u8*)0x15))
#define T2CON   (*((volatile u8*)0x12))
#define PR2     (*((volatile u8*)0x92))

#define CCP2CON (*((volatile u8*)0x1D))
#define CCPR2L  (*((volatile u8*)0x1B))

#define TMR2ON  2

#endif
