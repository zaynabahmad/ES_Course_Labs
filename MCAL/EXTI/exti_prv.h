#ifndef EXTI_PRV_H
#define EXTI_PRV_H

// PIC16F877A Interrupt Registers
#define INTCON_REG      *((volatile u8*)0x0B)
#define OPTION_REG      *((volatile u8*)0x81)

// INTCON bits
#define GIE     7   // Global Interrupt Enable
#define INTE    4   // External Interrupt Enable
#define INTF    1   // External Interrupt Flag

// OPTION_REG bits
#define INTEDG  6   // Interrupt Edge Select (1=Rising, 0=Falling)

#endif