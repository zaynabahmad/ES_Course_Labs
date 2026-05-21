/**
 * @file    EXTI_private.h
 * @brief   Register map for the INT0/RB0 external interrupt -- driver-internal.
 *
 * @details The mid-range PIC routes every interrupt through one vector, so the
 *          enable bit, the edge-select bit and the pending flag live in three
 *          different registers. They are gathered here so EXTI.c never carries
 *          a raw bit number in its logic.
 */
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "../SERVICES/Types.h"

/* INTCON -- interrupt control (address mirrored across all four banks). */
#define EXTI_ADDR_INTCON        0x0Bu
#define EXTI_REG_INTCON         ( *((volatile byte_t *)EXTI_ADDR_INTCON) )

/* OPTION_REG -- holds the INT edge-select bit (bank 1). */
#define EXTI_ADDR_OPTION        0x81u
#define EXTI_REG_OPTION         ( *((volatile byte_t *)EXTI_ADDR_OPTION) )

/* Bit positions inside INTCON. */
#define EXTI_BIT_GIE            7u      /* global interrupt enable           */
#define EXTI_BIT_INTE           4u      /* INT pin interrupt enable          */
#define EXTI_BIT_INTF           1u      /* INT pin interrupt pending flag    */

/* Bit position inside OPTION_REG. */
#define EXTI_BIT_INTEDG         6u      /* 1 = rising edge, 0 = falling edge */

#endif /* EXTI_PRIVATE_H */
