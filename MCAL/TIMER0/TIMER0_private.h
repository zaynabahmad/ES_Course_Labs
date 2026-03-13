#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/* Timer0 Registers */
#define TMR0       (*((volatile u8*)0x01)) // Timer0 register
#define OPTION_REG (*((volatile u8*)0x81))
#define INTCON     (*((volatile u8*)0x0B))

/* Bits in OPTION_REG */
#define T0CS    5   // Timer0 Clock Source Select bit
#define T0SE    4   // Timer0 Source Edge Select
#define PSA     3   // Prescaler Assignment bit
#define PS0     0   // Prescaler bits
#define PS1     1
#define PS2     2

#endif