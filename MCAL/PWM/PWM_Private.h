#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Timer2 Registers */
#define PR2         (*((volatile u8*)0x92))
#define T2CON       (*((volatile u8*)0x12))
#define TMR2        (*((volatile u8*)0x11))

/* T2CON Bits */
#define TMR2ON_BIT  2
#define T2CKPS0_BIT 0
#define T2CKPS1_BIT 1

/* CCP1 Registers */
#define CCP1CON     (*((volatile u8*)0x17))
#define CCPR1L      (*((volatile u8*)0x15))
#define CCPR1H      (*((volatile u8*)0x16))

/* CCP2 Registers */
#define CCP2CON     (*((volatile u8*)0x1D))
#define CCPR2L      (*((volatile u8*)0x1B))
#define CCPR2H      (*((volatile u8*)0x1C))

/* CCPxCON Bits */
#define CCP_DC1B0   4
#define CCP_DC1B1   5
#define CCP_M3      3
#define CCP_M2      2
#define CCP_M1      1
#define CCP_M0      0

/* TRISC bits for CCP pins */
#define TRISC       (*((volatile u8*)0x87))
#define CCP1_PIN    2   /* RC2/CCP1 */
#define CCP2_PIN    1   /* RC1/CCP2 */

#endif
