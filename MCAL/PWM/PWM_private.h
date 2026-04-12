#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Definitions for PIC16F877A - PWM Control */

/* CCP Module Registers */
#define CCPCON (*((volatile u8 *)0x17)) /* CCP Control Register */
#define CCPR1L (*((volatile u8 *)0x15)) /* PWM Duty Cycle (MSB) for CCP1 */
#define CCPR1H (*((volatile u8 *)0x1C)) /* PWM Duty Cycle (LSB) for CCP1 (PWM mode) */
#define CCPR2L (*((volatile u8 *)0x1B)) /* PWM Duty Cycle (MSB) for CCP2 */

/* Timer2 Registers (used for PWM base frequency) */
#define TMR2 (*((volatile u8 *)0x11))  /* Timer2 Register */
#define PR2 (*((volatile u8 *)0x12))   /* Timer2 Period Register */
#define T2CON (*((volatile u8 *)0x12)) /* Timer2 Control Register */

/* Status Registers */
#define PIR1 (*((volatile u8 *)0x0C))
#define T2IF 2 /* Timer2 Interrupt Flag */

/* Bit Definitions for PWM Mode */
#define PWM_MODE_BITS 0x0C /* PWM mode: 1100 in bits 3:2 */

/* Calculate PR2 and Prescaler for desired frequency */
#define PWM_FREQ_1KHZ 1000
#define PWM_FREQ_5KHZ 5000
#define PWM_FREQ_20KHZ 20000

#endif
