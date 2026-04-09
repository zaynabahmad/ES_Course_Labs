
#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "ext_int_test.h"

// Define the LED pin for the test 
#define TEST_LED_PORT  GPIO_PORTC
#define TEST_LED_PIN   GPIO_PIN0

// THE CALLBACK FUNCTION 

static void APP_ToggleLED_ISR(void)
{
    // Read the current state of the LED
    u8 current_state = GPIO_GetPinValue(TEST_LED_PORT, TEST_LED_PIN);

    // Toggle the LED state
    if(current_state == GPIO_HIGH)
    {
        GPIO_SetPinValue(TEST_LED_PORT, TEST_LED_PIN, GPIO_LOW);
    }
    else
    {
        GPIO_SetPinValue(TEST_LED_PORT, TEST_LED_PIN, GPIO_HIGH);
    }
}

// THE TEST FUNCTION

void APP_TestExtInt(void)
{
    // Initialize GPIO for the LED
    GPIO_Init();
    GPIO_SetPinDirection(TEST_LED_PORT, TEST_LED_PIN, GPIO_OUTPUT);

    // Initialize the External Interrupt driver
    EXT_INT_Init();

    // Set the trigger edge
    EXT_INT_SetEdge(rising_edge);

    // Pass our Application function to the MCAL layer
    EXT_INT_SetCallback(APP_ToggleLED_ISR);

    // Enable the interrupt
    EXT_INT_Enable();

    // The infinite background loop
    while(1)
    {
        // The microcontroller waits for the hardware to trigger the interrupt manager.
    }
}
