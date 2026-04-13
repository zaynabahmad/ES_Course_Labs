#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "SERVICES\STD_TYPES.h"

/* ── Register Addresses (PIC16F877A) ── */
#define TMR0        (*((volatile u8*)0x01))   /* Timer0 count register (Bank 0) */
#define OPTION_REG  (*((volatile u8*)0x81))   /* Timer0 config (Bank 1)         */
#define INTCON      (*((volatile u8*)0x0B))   /* Interrupt control               */

/* ── OPTION_REG Bits ── */
#define T0CS   5   /* Clock source select: 0=internal, 1=T0CKI pin */
#define T0SE   4   /* Source edge: 0=rising, 1=falling              */
#define PSA    3   /* Prescaler assignment: 0=Timer0, 1=WDT         */
#define PS2    2
#define PS1    1
#define PS0    0

/* ── INTCON Bits ── */
#define GIE    7
#define T0IE   5   /* Timer0 overflow interrupt enable  */
#define T0IF   2   /* Timer0 overflow interrupt flag    */

/* ── Prescaler Values (PS2:PS0) ── */
#define TIMER0_PRESCALER_2    0
#define TIMER0_PRESCALER_4    1
#define TIMER0_PRESCALER_8    2
#define TIMER0_PRESCALER_16   3
#define TIMER0_PRESCALER_32   4
#define TIMER0_PRESCALER_64   5
#define TIMER0_PRESCALER_128  6
#define TIMER0_PRESCALER_256  7

#endif