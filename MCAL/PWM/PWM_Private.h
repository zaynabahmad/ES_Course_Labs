#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A CCP & Timer2 registers */
#define CCP1CON     (*(volatile u8*)0x17)   /* Bank 0 */
#define CCPR1L      (*(volatile u8*)0x15)   /* Bank 0 */
#define CCP2CON     (*(volatile u8*)0x1D)   /* Bank 0 */
#define CCPR2L      (*(volatile u8*)0x1B)   /* Bank 0 */

#define TMR2        (*(volatile u8*)0x11)   /* Bank 0 */
#define T2CON       (*(volatile u8*)0x12)   /* Bank 0 */
#define PR2         (*(volatile u8*)0x92)   /* Bank 1 */

#ifndef TRISC
#define TRISC       (*(volatile u8*)0x87)   /* Bank 1 */
#endif

/* ================= T2CON bit positions ================= */
#define TMR2ON_BIT  2   /* Timer2 On bit */
#define T2CKPS1_BIT 1   /* Timer2 Clock Prescale bit 1 */
#define T2CKPS0_BIT 0   /* Timer2 Clock Prescale bit 0 */

/* ================= CCP Mode bits ================= */
#define PWM_MODE_MASK   0x0C  /* 1100 = PWM mode */

#endif