#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#ifndef OPTION_REG
#define OPTION_REG  (*((volatile u8*)0x81))
#endif

#ifndef INTCON
#define INTCON      (*((volatile u8*)0x0B))
#endif
#define TMR0        (*((volatile u8*)0x01))

/* OPTION_REG Bits */
#define T0CS    5
#define T0SE    4
#define PSA     3

/* INTCON Bits */
#define GIE     7
#define PEIE    6
#define TMR0IE  5
#define TMR0IF  2

#endif
