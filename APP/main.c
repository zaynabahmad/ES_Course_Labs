/* Include HAL layer */
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/SWITCH.h"

/* Include MCAL layer */
#include "../MCAL/EXT_INT/ext_int0.h"

/* Define our hardware pins for readability */
/* Note: Adjust LED_PORT to match your GPIO_interface.h macro for PORTC (often 2 or GPIO_PORTC) */
#define LED_PORT 2
#define LED_PIN 0
#define SWITCH_PIN 0 /* External Interrupt 0 (INT0) is HARDWIRED to PORTB, Pin 0 */

/* =====================================================================
 * CALLBACK FUNCTION
 * This function belongs to the Application Layer. It knows about the LED.
 * We will pass its address to the MCAL layer. When the interrupt happens,
 * the MCAL layer will call this function!
 * ===================================================================== */
void App_Toggle_LED(void)
{
    /* Toggle the LED using the HAL driver (Now passing both Port and Pin) */
    LED_Toggle(LED_PORT, LED_PIN);
}

/* =====================================================================
 * MAIN PROGRAM
 * ===================================================================== */
void main(void)
{
    /* 1. Initialize HAL Components */
    /* LED_Init requires Port and Pin according to your LED driver */
    LED_Init(LED_PORT, LED_PIN);
    SWITCH_Init(SWITCH_PIN);

    /* 2. Initialize and Configure MCAL Interrupt */
    EXT_INT0_Init();

    /* Set to trigger when the button is pressed (Assuming pull-up resistor is used) */
    EXT_INT0_SetEdge(EXT_INT0_FALLING_EDGE);

    /* 3. Register the Callback Function */
    /* We pass the name (which acts as an address pointer) of our function to the MCAL */
    EXT_INT0_SetCallback(App_Toggle_LED);

    /* 4. Enable the Interrupt to start listening */
    EXT_INT0_Enable();

    /* 5. Infinite Loop */
    while (1)
    {
        /* The main loop does absolutely nothing!
         * The microcontroller just waits. When you press the button,
         * the hardware forces it to jump to the ISR in ext_int0.c,
         * which then calls App_Toggle_LED() up here!
         */
    }
}