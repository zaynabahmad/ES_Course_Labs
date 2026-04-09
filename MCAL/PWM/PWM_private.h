#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ------- Register Definitions ------- */
#define TRISC (*((volatile u8 *)0x87))
#define T2CON (*((volatile u8 *)0x12))
#define PR2 (*((volatile u8 *)0x92))
#define CCPR1L (*((volatile u8 *)0x15))
#define CCP1CON (*((volatile u8 *)0x17))
#define TMR2 (*((volatile u8 *)0x11))

/* ------- Bit Positions ------- */
#define T2CON_TMR2ON 2  /* Timer2 On bit            */
#define T2CON_T2CKPS0 0 /* Prescaler bit 0          */
#define T2CON_T2CKPS1 1 /* Prescaler bit 1          */

/* CCP1CON bits 5:4 are the two LSBs of duty cycle */
#define CCP1CON_DC1B0 4
#define CCP1CON_DC1B1 5
/* CCP1CON mode bits 3:0 — 1100 = PWM mode          */
#define CCP1CON_CCP1M3 3
#define CCP1CON_CCP1M2 2

#endif