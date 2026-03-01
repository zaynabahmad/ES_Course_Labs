
#include "exti0_interface.h"            // Interface header for this module

// Pointer to callback function
static void (*EXTI0_Callback)(void) = 0;

// Initialize INT0 (RB0)
void EXTI0_Init(void) {
    TRISB.B0 = 1;        // RB0 as input
    OPTION_REG.B6 = 0;   // INTEDG = 0 -> interrupt on falling edge

    INTCON.B1 = 0;       // Clear INT0 interrupt flag (INT0IF)
    INTCON.B4 = 1;       // Enable INT0 interrupt (INTE)
    INTCON.B7 = 1;       // Enable global interrupts (GIE)
}

// Register a callback function
void EXTI0_SetCallback(void (*callback)(void)) {
    EXTI0_Callback = callback;
}

// Interrupt Service Routine
void interrupt() {
    if (INTCON.B1) {           // INT0IF
        if (EXTI0_Callback)
            EXTI0_Callback();  // Call registered callback

        INTCON.B1 = 0;         // Clear INT0 flag
    }
}