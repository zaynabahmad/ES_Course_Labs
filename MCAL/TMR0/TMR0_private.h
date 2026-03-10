#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

#define OPTION_REG  *((volatile u8*)0x81)
#define TMR0 *((volatile u8*)0x01)
#define INTCON  *((volatile u8*)0x0b)
#define GIE     7




/* OPTION_REG Bits */
#define PS0      0
#define PS1      1
#define PS2      2
#define PSA      3    // Prescaler Assignment bit
#define T0CS     5    // Clock Select bit
#define T0SE     4    // Edge Select bit

/* INTCON Bits (Interrupt Control) */
#define TMR0IE   5    // Timer0 Overflow Interrupt Enable
#define TMR0IF   2    // Timer0 Overflow Interrupt Flag
#define GIE      7    // Global Interrupt Enable



#define PRESCALER_2      0b000
#define PRESCALER_4      0b001
#define PRESCALER_8      0b010
#define PRESCALER_16     0b011
#define PRESCALER_32     0b100
#define PRESCALER_64     0b101
#define PRESCALER_128    0b110
#define PRESCALER_256    0b111

/* Clock Source Modes */
#define INTERNAL_CLK     0
#define TRANSITION_CLK   1

#endif