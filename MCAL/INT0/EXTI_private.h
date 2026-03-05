#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Register Addresses for PIC16F877A (or similar PIC) */
/* Adjust memory mapped addresses if your microcontroller varies */
#define INTCON      *((volatile u8*)0x0B)
#define OPTION_REG  *((volatile u8*)0x81)

/* INTCON Register Bits */
#define INTCON_GIE    7   /* Global Interrupt Enable */
#define INTCON_PEIE   6   /* Peripheral Interrupt Enable */
#define INTCON_TMR0IE 5   /* TMR0 Overflow Interrupt Enable */
#define INTCON_INTE   4   /* External Interrupt Enable */
#define INTCON_RBIE   3   /* RB Port Change Interrupt Enable */
#define INTCON_TMR0IF 2   /* TMR0 Overflow Interrupt Flag */
#define INTCON_INTF   1   /* External Interrupt Flag */
#define INTCON_RBIF   0   /* RB Port Change Interrupt Flag */

/* OPTION_REG Register Bits */
#define OPTION_REG_INTEDG 6   /* Interrupt Edge Select */

#endif