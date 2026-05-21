/**
 * @file    LED.h
 * @brief   HAL LED driver -- named indicators built on top of the GPIO MCAL.
 *
 * @details The HAL exists so the application can say "turn the alert LED on"
 *          without knowing which port, pin, or wiring polarity that means.
 *          Each LED is described once in the table inside LED.c; the rest of
 *          the firmware refers to it only by the enum value below.
 *
 *          This driver is intentionally a thin two-file module (no cfg/private
 *          split): it owns no registers of its own, only a small lookup table.
 */
#ifndef LED_H
#define LED_H

#include "../MCAL/GPIO_interface.h"

/**
 * @brief  Logical LEDs on the board. LED_COUNT is the table size -- keep it
 *         last so the driver can validate any index against it.
 */
typedef enum
{
    LED_STATUS = 0,         /**< heartbeat / "alive" indicator. */
    LED_ALERT,              /**< fault or attention indicator.  */
    LED_COUNT
} eLed_t;

/**
 * @brief  Configure one LED's pin as a driven output and leave it off.
 */
void vLED_Init(eLed_t eLed);

/** @brief Light the LED, honouring its configured active polarity. */
void vLED_On(eLed_t eLed);

/** @brief Extinguish the LED, honouring its configured active polarity. */
void vLED_Off(eLed_t eLed);

/** @brief Flip the LED -- the natural primitive for a blink heartbeat. */
void vLED_Toggle(eLed_t eLed);

#endif /* LED_H */
