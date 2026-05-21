/**
 * @file    PWM_interface.h
 * @brief   Public API of the CCP1 PWM driver.
 */
#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../SERVICES/Types.h"

/**
 * @brief  Put CCP1 in PWM mode, start the Timer2 time base prescaler and
 *         apply the default frequency. Output is held off until vPWM_Start().
 */
void vPWM_Init(void);

/**
 * @brief  Set the PWM carrier frequency.
 * @param  u32FreqHz  desired frequency in hertz.
 * @note   PR2 = Fosc / (4 * prescaler * freq) - 1; the prescaler divide is a
 *         switch-case so no run-time division by a variable is emitted.
 */
void vPWM_SetFreq(dword_t u32FreqHz);

/**
 * @brief  Set the duty cycle as a whole percentage.
 * @param  u8Percent  0..100; values above 100 are clamped to fully on.
 * @note   The 10-bit duty count is scaled against the current PR2 so the duty
 *         stays correct after any vPWM_SetFreq() change.
 */
void vPWM_SetDuty(byte_t u8Percent);

/** @brief Enable the Timer2 time base -- the pin starts switching. */
void vPWM_Start(void);

/** @brief Freeze the Timer2 time base -- the pin holds its last level. */
void vPWM_Stop(void);

#endif /* PWM_INTERFACE_H */
