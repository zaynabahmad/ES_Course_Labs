#include "EXT_INT.h"

// Global function pointer for the callback
static void (*INT0_CallBackPtr)(void) = 0;

void EXT_INT0_Init(void) {
    TRISB.F0 = 1;       // INT0 pin (RB0) as input
    EXT_INT0_SetEdge(1); // Default to rising edge
    EXT_INT0_Enable();
    INTCON.GIE = 1;     // Enable Global Interrupts
    INTCON.PEIE = 1;    // Enable Peripheral Interrupts
}

void EXT_INT0_Enable(void)  { INTCON.INTE = 1; }
void EXT_INT0_Disable(void) { INTCON.INTE = 0; }

void EXT_INT0_SetEdge(unsigned char edge_type) {
    if(edge_type == 1) OPTION_REG.INTEDG = 1; // Rising
    else OPTION_REG.INTEDG = 0;               // Falling
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    INT0_CallBackPtr = ptr;
}

// ISR - The only place where hardware flags are cleared
void interrupt() {
    if (INTCON.INTF) {
        if (INT0_CallBackPtr != 0) {
            INT0_CallBackPtr(); // Execute the App-level function
        }
        INTCON.INTF = 0; // Clear flag
    }
}