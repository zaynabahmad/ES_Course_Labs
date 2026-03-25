/**
 * @file    switch.c
 * @brief   PIC16F87X HAL Switch/Button Driver Implementation
 */

#include "switch.h"

/*============================================================
 * Software-delay debounce timing
 * At 4MHz Fosc, Fosc/4 = 1MHz → 1 instruction ≈ 1µs
 * Simple NOP loop for ~20ms debounce
 *============================================================*/
#define DEBOUNCE_DELAY_US   20000u   /* 20ms */
#define DEBOUNCE_SAMPLES    3u       /* Number of stable consecutive reads */

static void switch_delay_us(uint16_t us)
{
    uint16_t i;
    for (i = 0u; i < us; i++) {
        asm("NOP");
    }
}

/*------------------------------------------------------------
 * SWITCH_Init
 *------------------------------------------------------------*/
void SWITCH_Init(SWITCH_Handle_t *handle, const SWITCH_Config_t *cfg)
{
    /* Store configuration in handle */
    handle->port        = cfg->port;
    handle->pin         = cfg->pin;
    handle->activeLevel = cfg->activeLevel;

    /* Configure GPIO pin as input */
    GPIO_Config_t gpioCfg = {
        .port      = cfg->port,
        .pin       = cfg->pin,
        .direction = GPIO_INPUT,
        .initState = GPIO_LOW
    };
    GPIO_Init(&gpioCfg);

    /* Enable PORTB pull-ups if requested (only applies to PORTB) */
    if ((cfg->pullUp == SWITCH_PULLUP_ENABLE) && (cfg->port == GPIO_PORTB)) {
        GPIO_SetPortBPullUp(GPIO_PULLUP_ENABLE);
    }
}

/*------------------------------------------------------------
 * SWITCH_Read — raw read, no debounce
 *------------------------------------------------------------*/
SWITCH_State_t SWITCH_Read(const SWITCH_Handle_t *handle)
{
    GPIO_State_t pinLevel = GPIO_ReadPin(handle->port, handle->pin);

    if (handle->activeLevel == SWITCH_ACTIVE_LOW) {
        /* Active-low: pin LOW = pressed */
        return (pinLevel == GPIO_LOW) ? SWITCH_PRESSED : SWITCH_RELEASED;
    } else {
        /* Active-high: pin HIGH = pressed */
        return (pinLevel == GPIO_HIGH) ? SWITCH_PRESSED : SWITCH_RELEASED;
    }
}

/*------------------------------------------------------------
 * SWITCH_ReadDebounced — software debounce (~20ms)
 * Reads the switch multiple times with delays in between.
 * Returns a stable state only if all samples agree.
 *------------------------------------------------------------*/
SWITCH_State_t SWITCH_ReadDebounced(const SWITCH_Handle_t *handle)
{
    SWITCH_State_t first;
    SWITCH_State_t current;
    uint8_t stableCount = 0u;
    uint8_t i;

    first = SWITCH_Read(handle);

    for (i = 0u; i < DEBOUNCE_SAMPLES; i++) {
        switch_delay_us(DEBOUNCE_DELAY_US / DEBOUNCE_SAMPLES);
        current = SWITCH_Read(handle);

        if (current == first) {
            stableCount++;
        } else {
            /* Reset — start tracking from the new state */
            first = current;
            stableCount = 1u;
        }
    }

    /* If all consecutive samples matched, return that state */
    if (stableCount >= DEBOUNCE_SAMPLES) {
        return first;
    }

    /* Fallback: return last reading */
    return current;
}

/*------------------------------------------------------------
 * SWITCH_IsPressed
 *------------------------------------------------------------*/
uint8_t SWITCH_IsPressed(const SWITCH_Handle_t *handle)
{
    return (SWITCH_Read(handle) == SWITCH_PRESSED) ? 1u : 0u;
}
