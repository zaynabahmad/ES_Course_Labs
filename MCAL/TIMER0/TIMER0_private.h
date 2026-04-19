#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define OPTION_REG_REG    (*((volatile u8*)0x81))
#define TMR0_REG          (*((volatile u8*)0x01))
#define INTCON_REG        (*((volatile u8*)0x0B))

/* Bit Positions */
#define PSA_BIT           3
#define T0CS_BIT          5
#define TMR0IE_BIT        5
#define TMR0IF_BIT        2

#endif