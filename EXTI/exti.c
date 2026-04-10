// Purpose: Responds IMMEDIATELY when button is pressed (even if main code is busy)
// This is called an "interrupt" - it pauses main code, runs this, then resumes

#include "exti.h"

void (*EXTI_Callback)(void) = NULL;  // Stores what function to run

void EXTI_Init(EXTI_Edge edge) {
    TRISBbits.TRISB0 = 1;   // RB0 as input
    INTEDG = edge;           // Trigger on rising or falling edge
    EXTI_ClearFlag();        // Clear any old interrupt
}

void EXTI_Enable(void) {
    INTE = 1;    // Enable external interrupt
    GIE = 1;     // Enable global interrupts
    PEIE = 1;    // Enable peripheral interrupts
}

void EXTI_Disable(void) {
    INTE = 0;    // Disable external interrupt
}

void EXTI_ClearFlag(void) {
    INTF = 0;    // Clear interrupt flag
}

void EXTI_SetCallback(void (*callback)(void)) {
    EXTI_Callback = callback;  // Set which function to call
}

// Interrupt Service Routine - runs automatically when button pressed
void interrupt ISR(void) {
    if(INTF) {                  // If external interrupt happened
        INTF = 0;               // Clear the flag

        if(EXTI_Callback) {
            EXTI_Callback();    // Run the user's function
        }
    }
}