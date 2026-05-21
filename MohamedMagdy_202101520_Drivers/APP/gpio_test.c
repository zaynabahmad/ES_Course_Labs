#include "../MCAL/GPIO/GPIO_interface.h"
#include "gpio_test.h"

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

    GPIO_Init();

    GPIO_SetPinDirection(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_OUTPUT);

    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_HIGH);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_LOW);
    delay();

    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_HIGH);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_LOW);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_HIGH);
    delay();
    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, GPIO_LOW);

    GPIO_SetPinDirection(TEST_INPUT_PORT, TEST_INPUT_PIN, GPIO_INPUT);
    pin_state = GPIO_GetPinValue(TEST_INPUT_PORT, TEST_INPUT_PIN);

    GPIO_SetPinValue(TEST_OUTPUT_PORT, TEST_OUTPUT_PIN, pin_state);
}
