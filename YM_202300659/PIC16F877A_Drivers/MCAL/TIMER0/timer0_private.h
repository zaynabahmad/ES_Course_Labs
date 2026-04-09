/*
 * timer0_private.h
 * MCAL - Timer0 Register Definitions for PIC16F877A
 */

#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/* TMR0 - Timer0 Register (Bank 0) */
#define TMR0_REG        (*((volatile unsigned char*)0x01))

/* OPTION_REG (Bank 1) - Controls Timer0 */
#define OPTION_REG      (*((volatile unsigned char*)0x81))

/* OPTION_REG Bit Positions */
#define OPTION_RBPU     7    /* PORTB Pull-up Enable (active low) */
#define OPTION_INTEDG   6    /* INT Edge Select                   */
#define OPTION_T0CS     5    /* Timer0 Clock Source: 1=ext, 0=Fosc/4 */
#define OPTION_T0SE     4    /* Timer0 Source Edge: 1=falling, 0=rising */
#define OPTION_PSA      3    /* Prescaler Assignment: 1=WDT, 0=TMR0 */
#define OPTION_PS2      2    /* Prescaler bit 2 */
#define OPTION_PS1      1    /* Prescaler bit 1 */
#define OPTION_PS0      0    /* Prescaler bit 0 */

/* INTCON Bits for Timer0 */
#define INTCON_REG      (*((volatile unsigned char*)0x0B))
#define INTCON_GIE      7
#define INTCON_T0IE     5
#define INTCON_T0IF     2

/*
 * Prescaler Values for TMR0:
 * PS2:PS1:PS0 = 000 -> 1:2
 *             = 001 -> 1:4
 *             = 010 -> 1:8
 *             = 011 -> 1:16
 *             = 100 -> 1:32
 *             = 101 -> 1:64
 *             = 110 -> 1:128
 *             = 111 -> 1:256
 */

#endif /* TIMER0_PRIVATE_H */
