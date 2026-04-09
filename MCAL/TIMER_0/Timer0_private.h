#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/* Manual Register Definitions */
#define TMR0       (*((volatile u8 *)0x01))
#define OPTION_REG (*((volatile u8 *)0x81))
#define INTCON     (*((volatile u8 *)0x0B))

/* INTCON Bits */
#define T0IF_BIT 2
#define T0IE_BIT 5
#define GIE_BIT  7

/* OPTION_REG Bits */
#define T0SE_BIT 4
#define T0CS_BIT 5
#define PSA_BIT  3

#endif