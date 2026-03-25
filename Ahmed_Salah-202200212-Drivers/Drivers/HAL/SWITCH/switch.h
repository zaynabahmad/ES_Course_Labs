/**
 * @file    switch.h
 * @brief   PIC16F87X HAL Switch/Button Driver Header
 * @details Higher-level switch abstraction built on MCAL GPIO.
 *          Supports active-high and active-low buttons with
 *          optional software debouncing.
 */

#ifndef SWITCH_H
#define SWITCH_H

#include "../../MCAL/GPIO/gpio.h"

/*============================================================
 * Active Level — determines how the switch is wired
 *============================================================*/
typedef enum {
    SWITCH_ACTIVE_LOW  = 0,   /* Pressed = GND (with pull-up)  */
    SWITCH_ACTIVE_HIGH = 1    /* Pressed = VCC (with pull-down) */
} SWITCH_ActiveLevel_t;

/*============================================================
 * Switch State
 *============================================================*/
typedef enum {
    SWITCH_RELEASED = 0,
    SWITCH_PRESSED  = 1
} SWITCH_State_t;

/*============================================================
 * Pull-up Configuration
 *============================================================*/
typedef enum {
    SWITCH_PULLUP_DISABLE = 0,
    SWITCH_PULLUP_ENABLE  = 1   /* Only works on PORTB */
} SWITCH_PullUp_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    GPIO_Port_t          port;         /* Port where switch is connected  */
    GPIO_Pin_t           pin;          /* Pin number                      */
    SWITCH_ActiveLevel_t activeLevel;  /* Active-low or active-high       */
    SWITCH_PullUp_t      pullUp;       /* Enable PORTB pull-up (PORTB only) */
} SWITCH_Config_t;

/*============================================================
 * Switch Handle — stores runtime info for each switch instance
 *============================================================*/
typedef struct {
    GPIO_Port_t          port;
    GPIO_Pin_t           pin;
    SWITCH_ActiveLevel_t activeLevel;
} SWITCH_Handle_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize a switch input
 * @param  handle  Pointer to SWITCH_Handle_t (filled by this function)
 * @param  cfg     Pointer to SWITCH_Config_t
 */
void SWITCH_Init(SWITCH_Handle_t *handle, const SWITCH_Config_t *cfg);

/**
 * @brief  Read current switch state (no debounce)
 * @param  handle  Pointer to initialized SWITCH_Handle_t
 * @return SWITCH_PRESSED or SWITCH_RELEASED
 */
SWITCH_State_t SWITCH_Read(const SWITCH_Handle_t *handle);

/**
 * @brief  Read switch state with software debounce (~20ms)
 * @param  handle  Pointer to initialized SWITCH_Handle_t
 * @return SWITCH_PRESSED or SWITCH_RELEASED (stable reading)
 * @note   Blocking — introduces a small delay for debouncing
 */
SWITCH_State_t SWITCH_ReadDebounced(const SWITCH_Handle_t *handle);

/**
 * @brief  Check if switch is currently pressed
 * @param  handle  Pointer to initialized SWITCH_Handle_t
 * @return 1 if pressed, 0 if released
 */
uint8_t SWITCH_IsPressed(const SWITCH_Handle_t *handle);

#endif /* SWITCH_H */
