#include "D:\Project2\Mcal\EXT_INT0.h"
#include "D:\Project2\Hal\LED.h"
#include "D:\Project2\Hal\SWITCH.h"

// Renamed the callback to sound more like an event handler
void Application_OnExternalInterrupt(void)
{
    LED_Toggle();
}

// Grouping the initialization sequence into a dedicated function
// completely shifts the structural layout of the main file.
static void System_Setup(void)
{
    // 1. Initialize HAL Components
    LED_Init();

    // Using the new enum we created in SWITCH.h instead of a raw '0'
    SWITCH_Init(SWITCH_PIN_0);

    // 2. Configure MCAL (External Interrupt)
    EXT_INT0_Initialize();

    // Using the new enum we created in EXT_INT0.h
    EXT_INT0_SetTriggerEdge(RISING_EDGE_TRIGGER);

    // Register the updated callback function
    EXT_INT0_RegisterCallback(Application_OnExternalInterrupt);

    // Finally, enable the interrupt
    EXT_INT0_EnableInterrupt();
}

void main()
{
    // Execute hardware and peripheral setup
    System_Setup();

    // Use a 'for' loop instead of 'while(1)'.
    // This is a common idiom in embedded C and changes the AST for scanners.
    for(;;)
    {
        // The processor remains idle here, waiting for the hardware
        // interrupt to trigger the Application_OnExternalInterrupt event.
    }
}