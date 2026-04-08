#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


/* CCP1CON – Capture/Compare/PWM Control Register  (Bank 0: 0x17) */
#define CCP1CON         (*(volatile u8*)0x17)
#define CCP1CON_CCP1M3   3   
#define CCP1CON_CCP1M2   2
#define CCP1CON_DC1B1    5  
#define CCP1CON_DC1B0    4

/* CCPR1L – PWM Duty Cycle (8 MSBs)  (Bank 0: 0x15) */
#define CCPR1L          (*(volatile u8*)0x15)

/* T2CON – Timer2 Control Register  (Bank 0: 0x12) */
#define T2CON           (*(volatile u8*)0x12)
#define T2CON_TMR2ON     2   
#define T2CON_T2CKPS1    1   
#define T2CON_T2CKPS0    0

/* PR2 – Timer2 Period Register  (Bank 1: 0x92) */
#define PR2             (*(volatile u8*)0x92)

/* TRISC – needed to make CCP1 (RC2) an output  (Bank 1: 0x87) */
#define TRISC           (*(volatile u8*)0x87)
#define TRISC2           2


#define PWM_PR2_VALUE    99u   /* Gives 5 kHz @ 8 MHz, prescaler 1:4 */

/* 10-bit duty-cycle resolution = 4*(PR2+1) = 400 ticks               */
/* 25 % →  100 ticks  |  50 % → 200 ticks  |  75 % → 300 ticks       */
/* 100% →  400 ticks                                                    */
#define PWM_DUTY_25      100u
#define PWM_DUTY_50      200u
#define PWM_DUTY_75      300u
#define PWM_DUTY_100     400u

#endif /* PWM_PRIVATE_H */
