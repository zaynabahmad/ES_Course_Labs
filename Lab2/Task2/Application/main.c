#include "../MCAL/EXT_INT0/ext_int0.h"
#include "../HAL/LED/led.h"
#include "../HAL/SWITCH/switch.h"

// The Application logic that runs when the button is pressed
void App_Handler(void) {
    LED_Toggle();
}

void main() {
    // 1. Setup hardware via HAL
    LED_Init();
    SWITCH_Init(0); // Using 0 for RB0/INT0
    
    // 2. Setup Driver via MCAL
    EXT_INT0_Init();
    
    // 3. Register the App logic to the interrupt
    EXT_INT0_SetCallback(App_Handler);
    
    // 4. Go live
    EXT_INT0_Enable();

    while(1) {
        // Main loop is free for other tasks or low power mode
    }
}