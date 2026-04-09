 #ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

// ================= Registers =================

// TMR0 register
#define TMR0_REG     (*((volatile unsigned char*)0x01))

// OPTION_REG
#define OPTION_REG_REG  (*((volatile unsigned char*)0x81))

// INTCON register
#define INTCON_REG  (*((volatile unsigned char*)0x0B))


// ================= Bits =================

// INTCON bits
#define GIE_BIT   7
#define T0IE_BIT  5
#define T0IF_BIT  2

// OPTION_REG bits
#define T0CS_BIT  5   // Clock source
#define PSA_BIT   3   // Prescaler assignment
#define PS0_BIT   0
#define PS1_BIT   1
#define PS2_BIT   2



#endif