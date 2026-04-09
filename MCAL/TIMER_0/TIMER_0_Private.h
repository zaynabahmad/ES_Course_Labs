#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

/* Register Definitions for PIC16F877A Timer0 */

#define TMR0         (*((volatile u8*)0x01))
#define OPTION_REG   (*((volatile u8*)0x81))
#define INTCON       (*((volatile u8*)0x0B))

/* INTCON Bits */
#define T0IF    2
#define T0IE    5
#define GIE     7

/* OPTION_REG Bits */
#define PS0     0
#define PS1     1
#define PS2     2
#define PSA     3
#define T0SE    4
#define T0CS    5

#endif
