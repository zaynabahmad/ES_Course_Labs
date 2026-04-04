/*
 * gpio_test.c
 * Tests the GPIO MCAL driver: direction control, pin write, and pin read.
 * No direct register access — uses only GPIO_interface.h API.
 */

#include "../MCAL/GPIO/GPIO_interface.h"
#include "gpio_test.h"

/* ---- Pin assignments for the test ---- */
#define TEST_OUTPUT_PORT    GPIO_PORTD
#define TEST_OUTPUT_PIN     GPIO_PIN0

#define TEST_INPUT_PORT     GPIO_PORTB
#define TEST_INPUT_PIN      GPIO_PIN1

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000U; i++) { ; }
}

void GPIO_Test(void)
{
    u8 pin_state;

    /* Initialise all ports with default directions from GPIO_Config.h */
    GPIO_Init();

    /* --- Test 1: Set a pin as output and drive it high then low --- */
    GPIO_SetPinDirection(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_OUTPUT);

    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_HIGH);
    delay();

    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_LOW);
    delay();

    /* --- Test 2: Toggle several times --- */
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_HIGH);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_LOW);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_HIGH);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_LOW);

    /* --- Test 3: Configure a pin as input and read its value --- */
    GPIO_SetPinDirection(TEST_INPUT_PORT, TEST_INPUT_PIN, GPIO_INPUT);
    pin_state = GPIO_GetPinValue(TEST_INPUT_PORT, TEST_INPUT_PIN);

    /* Mirror the input state onto the output pin */
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, pin_state);
}