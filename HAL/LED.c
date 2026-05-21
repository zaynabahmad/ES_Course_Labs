/**
 * @file    LED.c
 * @brief   HAL LED driver implementation.
 *
 * @details The whole point of the HAL is wiring independence, so every
 *          board-specific fact about an LED -- its port, its pin, and whether
 *          it is wired active-high or active-low -- lives in the one table
 *          below. Re-wire the board and only this table changes; no APP code
 *          and no MCAL code is touched.
 */
#include "LED.h"

/** @brief Per-LED wiring description. */
typedef struct
{
    ePort_t  ePort;         /**< port the LED is wired to.            */
    byte_t   u8Pin;         /**< pin index on that port.              */
    eLevel_t eActive;       /**< level that lights the LED.           */
} sLedCfg_t;

/* Wiring table -- index matches the eLed_t enum order exactly. */
static const sLedCfg_t asLedTable[LED_COUNT] =
{
    /* LED_STATUS */ { GPIO_PORT_B, 0u, LEVEL_HIGH },
    /* LED_ALERT  */ { GPIO_PORT_B, 1u, LEVEL_HIGH }
};

/**
 * @brief  Resolve the level that switches an LED off (the opposite of active).
 */
static eLevel_t eIdleLevel(eLed_t eLed)
{
    return (asLedTable[eLed].eActive == LEVEL_HIGH) ? LEVEL_LOW : LEVEL_HIGH;
}

void vLED_Init(eLed_t eLed)
{
    if (eLed >= LED_COUNT)
    {
        return;                         /* ignore an unknown LED id. */
    }

    vGPIO_PinMode(asLedTable[eLed].ePort, asLedTable[eLed].u8Pin,
                  GPIO_DIR_OUTPUT);
    vLED_Off(eLed);                     /* defined power-up state. */
}

void vLED_On(eLed_t eLed)
{
    if (eLed < LED_COUNT)
    {
        vGPIO_PinWrite(asLedTable[eLed].ePort, asLedTable[eLed].u8Pin,
                       asLedTable[eLed].eActive);
    }
}

void vLED_Off(eLed_t eLed)
{
    if (eLed < LED_COUNT)
    {
        vGPIO_PinWrite(asLedTable[eLed].ePort, asLedTable[eLed].u8Pin,
                       eIdleLevel(eLed));
    }
}

void vLED_Toggle(eLed_t eLed)
{
    if (eLed >= LED_COUNT)
    {
        return;
    }

    /* Read the pin back and write its opposite -- works regardless of the
     * LED's active polarity, so no polarity branch is needed here. */
    switch (u8GPIO_PinRead(asLedTable[eLed].ePort, asLedTable[eLed].u8Pin))
    {
        case LEVEL_HIGH:
            vGPIO_PinWrite(asLedTable[eLed].ePort, asLedTable[eLed].u8Pin,
                           LEVEL_LOW);
            break;
        case LEVEL_LOW:
        default:
            vGPIO_PinWrite(asLedTable[eLed].ePort, asLedTable[eLed].u8Pin,
                           LEVEL_HIGH);
            break;
    }
}
