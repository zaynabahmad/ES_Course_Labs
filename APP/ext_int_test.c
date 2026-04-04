/*
 * ext_int_test.c
 * Tests the External Interrupt MCAL driver: init, edge configuration,
 * callback registration, and enable/disable.
 * No direct register access — uses only EXT_INT_Interface.h API.
 */

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "ext_int_test.h"

/* LED to toggle inside the interrupt callback */
#define INT_LED_PORT    GPIO_PORTD
#define INT_LED_PIN     GPIO_PIN2

static void delay(void)
{
    unsigned int i;
    for(i = 0; i < 30000U; i++) { ; }
}

/* Callback executed on each external interrupt event */
static void Button_ISR_Callback(void)
{
    u8 current;
    current = GPIO_GetPinValue(INT_LED_PORT, INT_LED_PIN);

    if(current == GPIO_HIGH)
    {
        GPIO_SetPinValue(INT_LED_PORT, INT_LED_PIN, GPIO_LOW);
    }
    else
    {
        GPIO_SetPinValue(INT_LED_PORT, INT_LED_PIN, GPIO_HIGH);
    }
}

void EXT_INT_Test(void)
{
    /* Configure indicator LED */
    GPIO_SetPinDirection(INT_LED_PORT, INT_LED_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(INT_LED_PORT, INT_LED_PIN, GPIO_LOW);

    /* Initialise external interrupt (configures RB0 as input, falling edge) */
    EXT_INT_Init();

    /* Register callback */
    EXT_INT_SetCallback(Button_ISR_Callback);

    /* Test edge selection: switch to rising edge then back to falling */
    EXT_INT_SetEdge(rising_edge);
    delay();
    EXT_INT_SetEdge(falling_edge);

    /* Enable the interrupt — LED will toggle on each button press */
    EXT_INT_Enable();

    /*
     * The test function returns; the interrupt fires asynchronously.
     * main() keeps the MCU alive in a while(1) loop.
     */
}