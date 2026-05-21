/**
 * @file    TMR0_private.h
 * @brief   Register map and timing constants for the Timer0 driver.
 *
 * @details Timer0 spans three registers: the count itself (TMR0), the
 *          prescaler/clock-source bits (OPTION_REG) and the run/flag bits
 *          (INTCON). The reciprocal of Tcy is kept as an integer so the
 *          preload maths stays in fixed-point and never pulls in float code.
 */
#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

#include "../SERVICES/Types.h"

#define TMR0_ADDR_TMR0          0x01u
#define TMR0_ADDR_OPTION        0x81u
#define TMR0_ADDR_INTCON        0x0Bu

#define TMR0_REG_COUNT          ( *((volatile byte_t *)TMR0_ADDR_TMR0)   )
#define TMR0_REG_OPTION         ( *((volatile byte_t *)TMR0_ADDR_OPTION) )
#define TMR0_REG_INTCON         ( *((volatile byte_t *)TMR0_ADDR_INTCON) )

/* OPTION_REG bits relevant to Timer0. */
#define TMR0_BIT_T0CS           5u      /* 0 = internal Fosc/4 clock         */
#define TMR0_BIT_PSA            3u      /* 0 = prescaler assigned to Timer0  */
/* PS2..PS0 occupy bits 2..0 -- written as a 3-bit field, not individually. */
#define TMR0_MASK_PS            0x07u

/* INTCON bits relevant to Timer0. */
#define TMR0_BIT_GIE            7u
#define TMR0_BIT_T0IE           5u      /* overflow interrupt enable         */
#define TMR0_BIT_T0IF           2u      /* overflow pending flag             */

/* Timer0 counts to 256 before it rolls over. */
#define TMR0_FULL_SCALE         256u

/* Ticks of the Fosc/4 clock per microsecond: 1 / 0.2 us = 5. Integer, so the
 * preload arithmetic stays free of floating point. */
#define TMR0_CYCLES_PER_US      5u

#endif /* TMR0_PRIVATE_H */
