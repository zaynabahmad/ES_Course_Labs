#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H

/*
 * Timer0 Configuration for PIC16F877A @ 8 MHz
 *
 * Timer0 clock = Fosc/4 = 2 MHz
 * With prescaler 1:256: tick period = 128 us
 * Overflow at TMR0=0xFF -> period = 256 * 128 us = ~32.8 ms
 *
 * To get ~10 ms overflow: counts = 10000 / 128 ≈ 78
 *   preload = 256 - 78 = 178
 * Actual period = 78 * 128 us = 9984 us ≈ 9.98 ms
 */

/* Prescaler select (see TIMER_0_Private.h for values) */
#define TIMER0_PRESCALER    TIMER0_PS_1_256

/* Timer0 preload value (0–255): TMR0 reloaded in ISR each overflow */
#define TIMER0_PRELOAD      178

/* Clock source: use internal oscillator (timer mode) */
#define TIMER0_CLK_INTERNAL 0

#endif