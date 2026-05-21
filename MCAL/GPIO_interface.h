/**
 * @file    GPIO_interface.h
 * @brief   Public API of the GPIO driver -- the only file HAL/APP may include.
 */
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../SERVICES/Types.h"

/** @brief Port selector. Values are contiguous so they double as table keys. */
typedef enum
{
    GPIO_PORT_A = 0,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E
} ePort_t;

/** @brief Pin data direction. Named, not 0/1, so call sites are self-documenting. */
typedef enum
{
    GPIO_DIR_OUTPUT = 0,
    GPIO_DIR_INPUT  = 1
} ePinDir_t;

/**
 * @brief  Set the data direction of a single pin.
 * @param  ePort  port the pin belongs to.
 * @param  u8Pin  pin index 0..7.
 * @param  eDir   GPIO_DIR_OUTPUT or GPIO_DIR_INPUT.
 * @note   Only the addressed bit of TRIS is touched, so neighbouring pins keep
 *         their direction -- callers may configure pins in any order.
 */
void vGPIO_PinMode(ePort_t ePort, byte_t u8Pin, ePinDir_t eDir);

/**
 * @brief  Drive an output pin to a logic level.
 * @param  eLevel  LEVEL_LOW or LEVEL_HIGH.
 * @note   Writing the port latch (not the pin) avoids the classic
 *         read-modify-write hazard on adjacent pins.
 */
void vGPIO_PinWrite(ePort_t ePort, byte_t u8Pin, eLevel_t eLevel);

/**
 * @brief  Sample an input pin.
 * @return LEVEL_HIGH or LEVEL_LOW as read from the port.
 */
eLevel_t u8GPIO_PinRead(ePort_t ePort, byte_t u8Pin);

/**
 * @brief  Set the direction of all eight pins of a port at once.
 * @param  u8Mask  bit = 1 -> input, bit = 0 -> output (mirrors TRIS layout).
 */
void vGPIO_PortMode(ePort_t ePort, byte_t u8Mask);

/**
 * @brief  Write all eight pins of a port in one latch update.
 */
void vGPIO_PortWrite(ePort_t ePort, byte_t u8Value);

/**
 * @brief  Enable or disable the weak internal pull-ups shared by all of PORTB.
 * @param  bEnable  FLAG_RAISED turns the pull-ups on, FLAG_CLEARED off.
 * @note   These exist only on PORTB; the control is global to the whole port,
 *         which is why it is a single call rather than a per-pin option. Used
 *         by active-low inputs (e.g. buttons) so they read a clean high when
 *         released without external resistors.
 */
void vGPIO_PortBPullups(flag_t bEnable);

#endif /* GPIO_INTERFACE_H */
