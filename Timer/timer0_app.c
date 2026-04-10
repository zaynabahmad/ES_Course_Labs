// Purpose: Tests timer by blinking LED every 500ms
// Uses timer instead of __delay_ms() (which stops the PIC)

#include "timer0.h"
#include "gpio.h"

void Timer0_Test(void) {
    // Setup LED on RB0
    GPIO_SetPinDirection(PORTB_ID, PIN0, OUTPUT);

    // Initialize timer
    Timer0_Init();

    while(1) {
        // Toggle LED (on->off or off->on)
        GPIO_TogglePin(PORTB_ID, PIN0);

        // Wait 500ms using timer
        Timer0_SetDelayMs(500);  // Set for 500ms delay
        Timer0_Start();          // Start counting
        while(!Timer0_IsOverflow());  // Wait for time to finish
        Timer0_Stop();           // Stop timer
        Timer0_ClearFlag();      // Clear flag for next time
    }
}