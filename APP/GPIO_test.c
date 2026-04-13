#include "SERVICES\BIT_MATH.h"
#include "SERVICES\STD_TYPES.h"
#include "HAL\LED\LED_interface.h"
#include "MCAL\GPIO\GPIO_interface.h"

#define GPIO_TEST_LED_PORT     GPIO_PORTA
#define GPIO_TEST_LED_PIN      GPIO_PIN0

#define GPIO_TEST_BUTTON_PORT  GPIO_PORTB
#define GPIO_TEST_BUTTON_PIN   GPIO_PIN0

void GPIO_Test(void)
{
    u8 button_state = 0;

    /* ── Test 1: Configure pins ── */
    LED_Init(GPIO_TEST_LED_PORT, GPIO_TEST_LED_PIN);                                    // PA0 → OUTPUT
    GPIO_SetPinDirection(GPIO_TEST_BUTTON_PORT, GPIO_TEST_BUTTON_PIN, GPIO_INPUT);      // PB0 → INPUT

    /* ── Test 2: Output test — blink LED 3 times at startup ── */
    u8 i;
    for (i = 0; i < 3; i++)
    {
        LED_On(GPIO_TEST_LED_PORT, GPIO_TEST_LED_PIN);      // PA0 = HIGH → LED ON

        u16 delay;
        for (delay = 0; delay < 60000; delay++);            // Software delay (~ON period)

        LED_Off(GPIO_TEST_LED_PORT, GPIO_TEST_LED_PIN);     // PA0 = LOW  → LED OFF

        for (delay = 0; delay < 60000; delay++);            // Software delay (~OFF period)
    }

    /* ── Test 3: Input test — LED mirrors button state ── */
    while (1)
    {
        button_state = GPIO_GetPinValue(GPIO_TEST_BUTTON_PORT, GPIO_TEST_BUTTON_PIN);   // Read PB0

        if (button_state == GPIO_HIGH)
        {
            LED_On(GPIO_TEST_LED_PORT, GPIO_TEST_LED_PIN);      // Button pressed  → LED ON
        }
        else
        {
            LED_Off(GPIO_TEST_LED_PORT, GPIO_TEST_LED_PIN);     // Button released → LED OFF
        }
    }
}