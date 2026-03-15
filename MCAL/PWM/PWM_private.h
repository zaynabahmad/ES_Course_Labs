#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP2CON (*((volatile u8*)0x1D))
#define CCP1CON (*((volatile u8*)0x17))
#define CCPR1L (*((volatile u8*)0x15))
#define CCPR2L (*((volatile u8*)0x1B))
#define CCPR1H (*((volatile u8*)0x16))
#define CCPR2H (*((volatile u8*)0x1C))
#define PR2 (*((volatile u8*)0x92))
#define T2CON (*((volatile u8*)0x12))
#define TMR2 (*((volatile u8*)0x11))  
#endif