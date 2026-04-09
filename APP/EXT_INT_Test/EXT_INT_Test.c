#include "EXT_INT_Test.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"

/* Select an arbitrary pin for the LED.
   Using PORTC PIN0, since PORTB PIN0 is typically the external interrupt pin. */
#define TEST_LED_PORT GPIO_PORTC
#define TEST_LED_PIN  GPIO_PIN0

/* Volatile flag to signal button press across contexts */
volatile u8 g_u8IsButtonPressed = 0;

/* Callback function to execute when external interrupt occurs */
void App_EXT_INT_Callback(void)
{
    /* Set flag and return immediately to keep ISR execution time short */
    g_u8IsButtonPressed = 1;
}

void EXT_INT_Test_Init(void)
{
    /* Initialize the LED */
    LED_Init(TEST_LED_PORT, TEST_LED_PIN);
    LED_Off(TEST_LED_PORT, TEST_LED_PIN);

    /* Initialize the External Interrupt */
    EXT_INT_Init();
    
    /* Set the edge trigger for external interrupt (e.g., falling edge for button press) */
    EXT_INT_SetEdge(falling_edge);
    
    /* Register the callback for the external interrupt */
    EXT_INT_SetCallback(App_EXT_INT_Callback);
    
    /* Enable the External Interrupt */
    EXT_INT_Enable();
}

void EXT_INT_Test_App(void)
{
    /* Check if the interrupt flag was set in the ISR */
    if (g_u8IsButtonPressed == 1)
    {
        /* Clear the flag */
        g_u8IsButtonPressed = 0;

        /* Toggle LED state in main context to avoid Reentrancy issues with GPIO functions */
        LED_Toggle(TEST_LED_PORT, TEST_LED_PIN);
    }
}
