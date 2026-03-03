#include "EXT_INT.h"
#include "LED.h"

// This is the function that will run when the button is pressed
void My_App_Task(void) {
    LED_Toggle();
}

void main() {
    // 1. Initialize HAL
    LED_Init();

    // 2. Initialize MCAL
    EXT_INT0_Init();

    // 3. Register the callback
    EXT_INT0_SetCallback(My_App_Task);

    while(1) {
        // Main loop stays empty or handles non-critical tasks
        // The LED toggle happens "automagically" via interrupt
    }
}