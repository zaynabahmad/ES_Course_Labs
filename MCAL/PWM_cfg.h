/**
 * @file    PWM_cfg.h
 * @brief   Compile-time configuration for the CCP1 PWM driver.
 *
 * @details PWM frequency on the PIC16F877A is set by the Timer2 period (PR2)
 *          and the Timer2 prescaler together. The prescaler is fixed here; the
 *          frequency is then free to be chosen at run time within the range
 *          that prescaler allows.
 */
#ifndef PWM_CFG_H
#define PWM_CFG_H

/** Timer2 prescaler feeding the PWM time base. Valid values: 1, 4, 16. */
#define PWM_TMR2_PRESCALER      16u

/** Frequency (Hz) applied by vPWM_Init() before any vPWM_SetFreq() call. */
#define PWM_DEFAULT_FREQ_HZ     1000uL

#endif /* PWM_CFG_H */
