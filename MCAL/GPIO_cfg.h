/**
 * @file    GPIO_cfg.h
 * @brief   Compile-time configuration for the GPIO driver.
 *
 * @details GPIO has no per-board tuning the way UART/ADC do, so this file only
 *          decides whether the driver spends code space validating its port
 *          and pin arguments. Leave the guard on during bring-up; switch it
 *          off for a release build to reclaim flash on the 8K-word part.
 */
#ifndef GPIO_CFG_H
#define GPIO_CFG_H

/** Set to 1 to range-check port/pin arguments, 0 to compile the checks out. */
#define GPIO_ARG_GUARD      1

/** Highest valid pin index on any port of the PIC16F877A (PORTA..D are 8-bit). */
#define GPIO_PIN_MAX        7u

#endif /* GPIO_CFG_H */
