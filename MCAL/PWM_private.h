/**
 * @file    PWM_private.h
 * @brief   Register map and timing constants for the CCP1 PWM driver.
 *
 * @details PWM output uses three blocks: CCP1 (mode + duty LSBs), Timer2
 *          (time base) and PORTC bit 2 (the physical CCP1 pin). The 10-bit
 *          duty value is split awkwardly across CCPR1L and two CCP1CON bits,
 *          so the split masks are spelled out here once.
 */
#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../SERVICES/Types.h"

#define PWM_REG_CCP1CON     ( *((volatile byte_t *)0x17u) )
#define PWM_REG_CCPR1L      ( *((volatile byte_t *)0x15u) )
#define PWM_REG_T2CON       ( *((volatile byte_t *)0x12u) )
#define PWM_REG_PR2         ( *((volatile byte_t *)0x92u) )
#define PWM_REG_TRISC       ( *((volatile byte_t *)0x87u) )

/* CCP1 output pin is RC2. */
#define PWM_PIN_CCP1        2u

/* CCP1CON: lower nibble = 1100 selects PWM mode; bits 5:4 carry duty LSBs. */
#define PWM_MODE_SELECT     0x0Cu
#define PWM_DUTY_LSB_SHIFT  4u          /* position of the 2 LSBs in CCP1CON */

/* T2CON bits. */
#define PWM_BIT_TMR2ON      2u

/* Fosc = 20 MHz; one PWM step is 4 * Tosc * prescaler wide. The factor 4 is
 * folded into the period formula in PWM.c. */
#define PWM_FOSC_HZ         20000000uL

#endif /* PWM_PRIVATE_H */
