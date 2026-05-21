/**
 * @file    test_gpio.c
 * @brief   GPIO / HAL exercise -- application layer, no register access.
 *
 * @details This file proves the layering holds: it drives LEDs and reads a
 *          button entirely through the HAL, so it contains no port names, no
 *          TRIS bits, nothing chip-specific. Re-target the board and this file
 *          compiles unchanged.
 */
#include "test_gpio.h"
#include "../HAL/LED.h"
#include "../HAL/BUTTON.h"

/** Heartbeat half-period in milliseconds. */
#define TEST_GPIO_BLINK_MS      500u

void vTest_Gpio(void)
{
    vLED_Init(LED_STATUS);
    vLED_Init(LED_ALERT);
    vBUTTON_Init(BTN_USER);

    while (1)
    {
        /* LED_STATUS is the "alive" heartbeat. */
        vLED_Toggle(LED_STATUS);

        /* LED_ALERT follows the button so the debounce can be seen by eye. */
        switch (bBUTTON_IsHeld(BTN_USER))
        {
            case FLAG_RAISED: vLED_On(LED_ALERT);  break;
            default:          vLED_Off(LED_ALERT); break;
        }

        Delay_ms(TEST_GPIO_BLINK_MS);
    }
}
