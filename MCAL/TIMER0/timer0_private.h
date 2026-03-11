#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

// Register definitions for Timer0
#define TMR0 (*((volatile u8*)0x01))  // Timer0 Register
#define INTCON (*((volatile u8*)0x0B))  // Interrupt Control Register
#define OPTION_REG (*((volatile u8*)0x81))

// Bit definitions for INTCON register
#define GIE 7   // Global Interrupt Enable
#define T0IE 5  // Timer0 Interrupt Enable
#define T0IF 2  // Timer0 Interrupt Flag

// Bit definitions for OPTION_REG register
#define T0CS 5  // Timer0 Clock Source Select
#define PSA 3   // Prescaler Assignment
#define PS0 0   // Prescaler Rate Select bit 0
#define PS1 1   // Prescaler Rate Select bit 1
#define PS2 2   // Prescaler Rate Select bit 2

#endif