/**
 * @file    BUTTON.c
 * @brief   HAL button driver implementation.
 *
 * @details Debouncing here is a confirm-twice scheme rather than a timer: the
 *          pin is sampled, given a short settle delay, then sampled again, and
 *          a press is only reported if both samples agree. It is cheap, needs
 *          no peripheral, and is more than enough for human button presses.
 */
#include "BUTTON.h"

/** Settle window between the two debounce samples, in milliseconds. */
#define BUTTON_DEBOUNCE_MS      15u

/** @brief Per-button wiring description. */
typedef struct
{
    ePort_t  ePort;         /**< port the button is wired to.          */
    byte_t   u8Pin;         /**< pin index on that port.               */
    eLevel_t ePressed;      /**< level seen while the button is held.  */
} sButtonCfg_t;

/* Wiring table -- index matches the eButton_t enum order exactly. */
static const sButtonCfg_t asButtonTable[BTN_COUNT] =
{
    /* BTN_USER */ { GPIO_PORT_B, 4u, LEVEL_LOW },   /* active-low, pulled up */
    /* BTN_MODE */ { GPIO_PORT_B, 5u, LEVEL_LOW }
};

void vBUTTON_Init(eButton_t eButton)
{
    if (eButton < BTN_COUNT)
    {
        vGPIO_PinMode(asButtonTable[eButton].ePort,
                      asButtonTable[eButton].u8Pin, GPIO_DIR_INPUT);

        /* An active-low button on PORTB needs a pull-up to read high when
         * released; enable the internal ones so no external resistor is
         * required. (The pull-ups are PORTB-wide, hence the port check.) */
        if ((asButtonTable[eButton].ePort == GPIO_PORT_B) &&
            (asButtonTable[eButton].ePressed == LEVEL_LOW))
        {
            vGPIO_PortBPullups(FLAG_RAISED);
        }
    }
}

flag_t bBUTTON_IsHeld(eButton_t eButton)
{
    eLevel_t eFirst;
    eLevel_t eSecond;

    if (eButton >= BTN_COUNT)
    {
        return FLAG_CLEARED;
    }

    /* First sample, settle, second sample -- a bounce will make the two
     * disagree, and a disagreement is reported as "not pressed". */
    eFirst = u8GPIO_PinRead(asButtonTable[eButton].ePort,
                            asButtonTable[eButton].u8Pin);
    Delay_ms(BUTTON_DEBOUNCE_MS);
    eSecond = u8GPIO_PinRead(asButtonTable[eButton].ePort,
                             asButtonTable[eButton].u8Pin);

    if ((eFirst == eSecond) && (eFirst == asButtonTable[eButton].ePressed))
    {
        return FLAG_RAISED;
    }

    return FLAG_CLEARED;
}
