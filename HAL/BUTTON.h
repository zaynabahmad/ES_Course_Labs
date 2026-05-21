/**
 * @file    BUTTON.h
 * @brief   HAL button driver -- debounced inputs built on the GPIO MCAL.
 *
 * @details Like the LED driver, this is a thin two-file HAL module. It hides
 *          two things from the application: the pin wiring, and the fact that
 *          a mechanical contact bounces. APP code asks a yes/no question and
 *          gets a clean answer.
 */
#ifndef BUTTON_H
#define BUTTON_H

#include "../MCAL/GPIO_interface.h"

/**
 * @brief  Logical buttons on the board. BTN_COUNT is the table size.
 */
typedef enum
{
    BTN_USER = 0,           /**< general-purpose user push-button. */
    BTN_MODE,               /**< mode / select push-button.        */
    BTN_COUNT
} eButton_t;

/**
 * @brief  Configure one button's pin as an input.
 */
void vBUTTON_Init(eButton_t eButton);

/**
 * @brief  Report whether a button is currently held down.
 * @return FLAG_RAISED if pressed (confirmed past contact bounce),
 *         FLAG_CLEARED otherwise.
 */
flag_t bBUTTON_IsHeld(eButton_t eButton);

#endif /* BUTTON_H */
