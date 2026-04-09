#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/* Timer0 Initial Value */
#define TMR0_INIT_VAL 0x06

/* Clock Source: INTERNAL (0) or EXTERNAL (1) */
#define TMR0_CLOCK_SOURCE INTERNAL

/* External Clock Edge (if EXTERNAL): LOW2HIGH (0) or HIGH2LOW (1) */
#define TMR0_EXT_EDGE LOW2HIGH

/* Prescaler Assignment: PSA_LOW (0 - to Timer0) or PSA_HIGH (1 - to WDT) */
#define TMR0_PRESCALER_ASSIGN PSA_LOW

/* Prescaler Rate Options: OPT_2, OPT_4, OPT_8, OPT_16, OPT_32, OPT_64, OPT_128, OPT_256 */
#define TMR0_PRESCALER_RATE OPT_8

#endif