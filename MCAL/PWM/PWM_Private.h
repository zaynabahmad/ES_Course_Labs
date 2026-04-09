#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* Register Definitions for PIC16F877A PWM */

#define PR2         (*((volatile u8*)0x92))
#define T2CON       (*((volatile u8*)0x12))
#define TMR2        (*((volatile u8*)0x11))

#define CCPR1L      (*((volatile u8*)0x15))
#define CCP1CON     (*((volatile u8*)0x17))

#define CCPR2L      (*((volatile u8*)0x1B))
#define CCP2CON     (*((volatile u8*)0x1D))

/* CCP1CON & CCP2CON Bits */
#define CCPxM3      3
#define CCPxM2      2
#define CCPxM1      1
#define CCPxM0      0
#define CCPxY       4
#define CCPxX       5

/* T2CON Bits */
#define TMR2ON      2

#endif
