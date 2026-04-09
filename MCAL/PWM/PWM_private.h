#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* --- Register Definitions --- */
#define CCPR1L  (*((volatile u8 *)0x15))
#define CCP1CON (*((volatile u8 *)0x17))
#define CCPR2L  (*((volatile u8 *)0x1B))
#define CCP2CON (*((volatile u8 *)0x1D))
#define PR2     (*((volatile u8 *)0x92))
#define T2CON   (*((volatile u8 *)0x12))

/* --- CCP1CON/CCP2CON Bits --- */
#define CCPxM0_BIT 0
#define CCPxM1_BIT 1
#define CCPxM2_BIT 2
#define CCPxM3_BIT 3
#define CCPxX_BIT  4  /* LSB 0 of Duty Cycle */
#define CCPxY_BIT  5  /* LSB 1 of Duty Cycle */

/* --- T2CON Bits --- */
#define T2CKPS0_BIT 0
#define T2CKPS1_BIT 1
#define TMR2ON_BIT  2

#endif