/*
 * exti.h
 * External Interrupt Driver for PIC16F877A
 *
 * PIC16F877A external interrupts:
 *   INT  — RB0/INT pin, edge selectable (INTEDG bit in OPTION_REG)
 *   RB   — RB4-RB7 port change interrupt
 */

#ifndef EXTI_H
#define EXTI_H

#include "../std_types.h"
#include <xc.h>

typedef enum {
    EXTI_INT_PIN,       /* RB0/INT  — rising or falling edge */
    EXTI_RB_CHANGE      /* RB4-RB7  — any logic change       */
} EXTI_Source;

typedef enum {
    EXTI_FALLING_EDGE,
    EXTI_RISING_EDGE
} EXTI_Edge;

/* Call before sei-equivalent (GIE) */
void EXTI_init  (EXTI_Source src, EXTI_Edge edge);
void EXTI_enable (EXTI_Source src);
void EXTI_disable(EXTI_Source src);

#endif /* EXTI_H */
