/**
 * @file    led.c
 * @brief   PIC16F87X HAL LED Driver Implementation
 */

#include "led.h"

/*------------------------------------------------------------
 * Internal: map LED logical state to GPIO physical level
 *------------------------------------------------------------*/
static GPIO_State_t led_map_state(LED_ActiveLevel_t activeLevel, LED_State_t state)
{
    if (activeLevel == LED_ACTIVE_HIGH) {
        return (state == LED_ON) ? GPIO_HIGH : GPIO_LOW;
    } else {
        /* Active-low: ON → LOW, OFF → HIGH */
        return (state == LED_ON) ? GPIO_LOW : GPIO_HIGH;
    }
}

/*------------------------------------------------------------
 * LED_Init
 *------------------------------------------------------------*/
void LED_Init(LED_Handle_t *handle, const LED_Config_t *cfg)
{
    /* Store configuration in handle */
    handle->port        = cfg->port;
    handle->pin         = cfg->pin;
    handle->activeLevel = cfg->activeLevel;
    handle->currentState = cfg->initState;

    /* Configure GPIO pin as output with correct initial level */
    GPIO_Config_t gpioCfg = {
        .port      = cfg->port,
        .pin       = cfg->pin,
        .direction = GPIO_OUTPUT,
        .initState = led_map_state(cfg->activeLevel, cfg->initState)
    };
    GPIO_Init(&gpioCfg);
}

/*------------------------------------------------------------
 * LED_On
 *------------------------------------------------------------*/
void LED_On(LED_Handle_t *handle)
{
    handle->currentState = LED_ON;
    GPIO_WritePin(handle->port, handle->pin,
                  led_map_state(handle->activeLevel, LED_ON));
}

/*------------------------------------------------------------
 * LED_Off
 *------------------------------------------------------------*/
void LED_Off(LED_Handle_t *handle)
{
    handle->currentState = LED_OFF;
    GPIO_WritePin(handle->port, handle->pin,
                  led_map_state(handle->activeLevel, LED_OFF));
}

/*------------------------------------------------------------
 * LED_Toggle
 *------------------------------------------------------------*/
void LED_Toggle(LED_Handle_t *handle)
{
    if (handle->currentState == LED_ON) {
        LED_Off(handle);
    } else {
        LED_On(handle);
    }
}

/*------------------------------------------------------------
 * LED_Write
 *------------------------------------------------------------*/
void LED_Write(LED_Handle_t *handle, LED_State_t state)
{
    if (state == LED_ON) {
        LED_On(handle);
    } else {
        LED_Off(handle);
    }
}

/*------------------------------------------------------------
 * LED_GetState
 *------------------------------------------------------------*/
LED_State_t LED_GetState(const LED_Handle_t *handle)
{
    return handle->currentState;
}
