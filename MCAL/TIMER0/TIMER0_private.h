#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TMR0_REG    *((volatile unsigned char*)0x01)
#define INTCON_REG  *((volatile unsigned char*)0x0B)
#define OPTION_REG  *((volatile unsigned char*)0x81)

// INTCON bits
#define TMR0IE 5
#define TMR0IF 2
#define GIE    7

// OPTION_REG bits
#define PSA 3
#define PS0 0
#define PS1 1
#define PS2 2
#define T0CS 5

#endif