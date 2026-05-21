/**
 * @file    TMR0_interface.h
 * @brief   Public API of the Timer0 driver.
 */
#ifndef TMR0_INTERFACE_H
#define TMR0_INTERFACE_H

#include "../SERVICES/Types.h"

/** @brief Signature of the routine run on each Timer0 overflow. */
typedef void (*pfTMR0_Callback_t)(void);

/**
 * @brief  Select the internal clock and apply the configured prescaler.
 * @note   The counter is left stopped (interrupt masked) so the caller can
 *         set a preload before the first tick is allowed to count.
 */
void vTMR0_Init(void);

/**
 * @brief  Load the counter so it overflows after @p u16Microseconds.
 * @param  u16Microseconds  desired interval; values longer than the prescaler
 *                          allows are clamped to the full 8-bit span.
 * @note   Preload = 256 - (us * 5 / prescaler); the divide is selected with a
 *         switch-case on the configured prescaler value.
 */
void vTMR0_SetPreload(word_t u16Microseconds);

/**
 * @brief  Clear the pending flag and unmask the overflow interrupt.
 */
void vTMR0_Start(void);

/**
 * @brief  Mask the overflow interrupt; the counter itself keeps running.
 */
void vTMR0_Stop(void);

/**
 * @brief  Register the routine the ISR dispatches to on each overflow.
 */
void vTMR0_SetCallback(pfTMR0_Callback_t pfCallback);

/**
 * @brief  Per-source interrupt handler -- called by the single global ISR.
 */
void vTMR0_IsrHandler(void);

#endif /* TMR0_INTERFACE_H */
