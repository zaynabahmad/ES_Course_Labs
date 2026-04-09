        #ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

// Timer0 Registers
#define TMR0        (*((volatile u8*)0x01))
#define OPTION_REG  (*((volatile u8*)0x81))
#define INTCON      (*((volatile u8*)0x0B))

// OPTION_REG Bits 
#define T0CS    5
#define T0SE    4
#define PSA     3
#define PS2     2
#define PS1     1
#define PS0     0

// INTCON Bits
#define GIE     7
#define T0IE    5
#define T0IF    2

#endif