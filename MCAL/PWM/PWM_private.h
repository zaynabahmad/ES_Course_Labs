#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Addresses */
#define CCP1CON (*((volatile u8*)0x17))
#define CCPR1L  (*((volatile u8*)0x15))
#define CCPR1H  (*((volatile u8*)0x16))
#define T2CON   (*((volatile u8*)0x12))
#define TMR2    (*((volatile u8*)0x11))
#define PR2     (*((volatile u8*)0x92))

/* CCP1CON bits */
#define DC1B1_BIT   5   /* Duty cycle LSB bit 1 */
#define DC1B0_BIT   4   /* Duty cycle LSB bit 0 */
#define CCP1M3_BIT  3
#define CCP1M2_BIT  2
#define CCP1M1_BIT  1
#define CCP1M0_BIT  0

/* T2CON bits */
#define TMR2ON_BIT  2   /* Timer2 on */
#define T2CKPS1_BIT 1   /* Prescaler bit 1 */
#define T2CKPS0_BIT 0   /* Prescaler bit 0 */

#endif
