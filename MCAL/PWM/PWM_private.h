#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* CCP1CON register — address 0x17 */
#define CCP1CON            (*((volatile u8*)0x17))
#define CCP1CON_DC1B1      5    /* Duty cycle LSB bit 1  */
#define CCP1CON_DC1B0      4    /* Duty cycle LSB bit 0  */

/* CCPR1L — Duty cycle MSBs (8 bits), address 0x15 */
#define CCPR1L             (*((volatile u8*)0x15))

/* T2CON register — Timer2 control, address 0x12 */
#define T2CON              (*((volatile u8*)0x12))
#define T2CON_TMR2ON       2    /* Timer2 enable         */
#define T2CON_T2CKPS1      1    /* Prescaler select bit1 */
#define T2CON_T2CKPS0      0    /* Prescaler select bit0 */

/* PR2 — Timer2 period register, Bank 1, address 0x92 */
#define PR2                (*((volatile u8*)0x92))

/* TRISC — RC2/CCP1 pin direction, Bank 1, address 0x87 */
#define TRISC              (*((volatile u8*)0x87))
#define TRISC_CCP1PIN      2    /* RC2 = CCP1 output pin */

/* CCP1 PWM mode: CCP1CON bits 3:0 = 1100 */
#define CCP1_PWM_MODE      0x0Cu

#endif
