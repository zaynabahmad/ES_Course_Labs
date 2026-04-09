#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/*
 * PWM Configuration for PIC16F877A @ 8 MHz
 *
 * PWM frequency = Fosc / (4 * (PR2 + 1) * prescaler)
 *
 * Default: 8 kHz PWM with prescaler 1:1
 *   PR2 = 8000000 / (4 * 8000 * 1) - 1 = 249   (exact)
 *
 * Resolution: 10-bit (CCPR1L:DC1B1:DC1B0) — max value = 4*(PR2+1) = 1000
 */

/* CPU frequency in Hz (must match system clock) */
#define PWM_FOSC            8000000UL

/* Timer2 prescaler selection (see PWM_Private.h: T2CKPS_1, T2CKPS_4, T2CKPS_16) */
#define PWM_T2_PRESCALER    T2CKPS_1

/* Numeric prescaler divisor matching the selection above */
#define PWM_T2_PRESCALER_VAL   1UL

/* Default PWM frequency in Hz */
#define PWM_DEFAULT_FREQ    8000UL

/*
 * PR2 = (Fosc / (4 * freq * prescaler)) - 1
 * For 8 kHz at 8 MHz with prescaler 1 → PR2 = 249
 */
#define PWM_PR2_VALUE \
    ((u8)((PWM_FOSC / (4UL * PWM_DEFAULT_FREQ * PWM_T2_PRESCALER_VAL)) - 1UL))

#endif