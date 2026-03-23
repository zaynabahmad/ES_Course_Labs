/**
 * @file    led.h
 * @brief   PIC16F87X HAL LED Driver Header
 * @details Higher-level LED abstraction built on MCAL GPIO.
 *          Supports active-high and active-low LED configurations.
 */

#ifndef LED_H
#define LED_H

#include "../../MCAL/GPIO/gpio.h"

/*============================================================
 * Active Level — determines how LED is wired
 *============================================================*/
typedef enum {
    LED_ACTIVE_HIGH = 0,   /* LED on when pin = HIGH (anode to pin, cathode to GND) */
    LED_ACTIVE_LOW  = 1    /* LED on when pin = LOW  (cathode to pin, anode to VCC) */
} LED_ActiveLevel_t;

/*============================================================
 * LED State
 *============================================================*/
typedef enum {
    LED_OFF = 0,
    LED_ON  = 1
} LED_State_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    GPIO_Port_t        port;         /* Port where LED is connected     */
    GPIO_Pin_t         pin;          /* Pin number                      */
    LED_ActiveLevel_t  activeLevel;  /* Active-high or active-low       */
    LED_State_t        initState;    /* Initial state after init        */
} LED_Config_t;

/*============================================================
 * LED Handle — stores runtime info for each LED instance
 *============================================================*/
typedef struct {
    GPIO_Port_t        port;
    GPIO_Pin_t         pin;
    LED_ActiveLevel_t  activeLevel;
    LED_State_t        currentState;
} LED_Handle_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize an LED
 * @param  handle  Pointer to LED_Handle_t (filled by this function)
 * @param  cfg     Pointer to LED_Config_t
 */
void LED_Init(LED_Handle_t *handle, const LED_Config_t *cfg);

/**
 * @brief  Turn LED on
 * @param  handle  Pointer to initialized LED_Handle_t
 */
void LED_On(LED_Handle_t *handle);

/**
 * @brief  Turn LED off
 * @param  handle  Pointer to initialized LED_Handle_t
 */
void LED_Off(LED_Handle_t *handle);

/**
 * @brief  Toggle LED state
 * @param  handle  Pointer to initialized LED_Handle_t
 */
void LED_Toggle(LED_Handle_t *handle);

/**
 * @brief  Write a specific state to LED
 * @param  handle  Pointer to initialized LED_Handle_t
 * @param  state   LED_ON or LED_OFF
 */
void LED_Write(LED_Handle_t *handle, LED_State_t state);

/**
 * @brief  Get current LED state
 * @param  handle  Pointer to initialized LED_Handle_t
 * @return LED_ON or LED_OFF
 */
LED_State_t LED_GetState(const LED_Handle_t *handle);

#endif /* LED_H */
