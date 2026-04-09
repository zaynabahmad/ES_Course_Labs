/*
 * exti_private.h
 * MCAL - External Interrupt Register Definitions for PIC16F877A
 * Private file - NOT to be included by APP layer
 */

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* =====================================================
 * Interrupt Control Registers
 * ===================================================== */

/* INTCON - Interrupt Control Register (Bank 0/1) */
#define INTCON_REG    (*((volatile unsigned char*)0x0B))

#define INTCON_GIE    7    /* Global Interrupt Enable     */
#define INTCON_PEIE   6    /* Peripheral Interrupt Enable */
#define INTCON_T0IE   5    /* Timer0 Interrupt Enable     */
#define INTCON_INTE   4    /* RB0/INT External Int Enable */
#define INTCON_RBIE   3    /* RB Port Change Int Enable   */
#define INTCON_T0IF   2    /* Timer0 Overflow Flag        */
#define INTCON_INTF   1    /* RB0/INT External Int Flag   */
#define INTCON_RBIF   0    /* RB Port Change Flag         */

/* OPTION_REG - Option Register (Bank 1) */
#define OPTION_REG_ADDR  (*((volatile unsigned char*)0x81))
#define OPTION_INTEDG    6    /* Interrupt Edge Select: 1=rising, 0=falling */

/* PIE1 - Peripheral Interrupt Enable 1 (Bank 1) */
#define PIE1_REG      (*((volatile unsigned char*)0x8C))

/* PIR1 - Peripheral Interrupt Request Flags 1 (Bank 0) */
#define PIR1_REG      (*((volatile unsigned char*)0x0C))

#endif /* EXTI_PRIVATE_H */
