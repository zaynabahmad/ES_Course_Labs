/**
 * @file    TMR0_cfg.h
 * @brief   Compile-time configuration for the Timer0 driver.
 *
 * @details Timer0 counts at Fosc/4 (Tcy = 0.2 us at 20 MHz) divided by the
 *          prescaler. The prescaler is the only setting that changes the
 *          longest interval the 8-bit counter can measure, so it is fixed
 *          here and the preload maths in TMR0.c reads it back.
 */
#ifndef TMR0_CFG_H
#define TMR0_CFG_H

/**
 * Prescaler divider applied to the Timer0 clock.
 * Valid values: 2, 4, 8, 16, 32, 64, 128, 256.
 * 64 gives a tick of 12.8 us and a full-count span of ~3.28 ms at 20 MHz.
 */
#define TMR0_PRESCALER_DIV      64u

#endif /* TMR0_CFG_H */
