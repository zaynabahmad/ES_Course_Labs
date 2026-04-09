#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP1CON  (*((volatile u8*)0x17))
#define CCPR1L   (*((volatile u8*)0x15))

#define T2CON    (*((volatile u8*)0x12))
#define PR2      (*((volatile u8*)0x92))

#define TRISC    (*((volatile u8*)0x87))

#endif