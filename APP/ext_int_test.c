#include "ext_int_test.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

// 1. Add the volatile flag
volatile unsigned char interruptHappened = 0;
static u8 led_state = 0;

void EXT_INT_ToggleLED(void)
{
    // 2. Just leave the "note" that the interrupt fired!
    // Do NOT call GPIO_SetPinValue here.
    interruptHappened = 1;
}

void APP_EXT_INT_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
    EXT_INT_SetEdge(EXT_INT_RISING_EDGE);
    EXT_INT_SetCallback(EXT_INT_ToggleLED);
    EXT_INT_Init();
    EXT_INT_Enable();

    while (1)
    {
        // 3. Check for the note in the main loop
        if (interruptHappened == 1)
        {
            // Toggle the LED state variable
            led_state ^= 1;
            
            // NOW it is safe to change the hardware pin!
            GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, led_state);
            
            // 4. Reset the flag so it waits for the next interrupt
            interruptHappened = 0;
        }
    }
}