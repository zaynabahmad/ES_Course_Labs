#include "timer0.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*timer_callback)(void) = 0;

void TIMER0_Init(void) {
    // Prescaler 1:256 for 8MHz (10ms tick)
    OPTION_REG.PS0 = 1;
    OPTION_REG.PS1 = 1;
    OPTION_REG.PS2 = 1;
    OPTION_REG.PSA = 0;   // Assign prescaler to Timer0
    OPTION_REG.T0CS = 0;  // Internal instruction cycle clock

    TMR0 = 178;           // Preload for 10ms
}

void TIMER0_Start(void) {
    T0IF_bit = 0;         // Clear Timer0 Overflow Interrupt Flag
    T0IE_bit = 1;         // Enable Timer0 Overflow Interrupt
    GIE_bit  = 1;         // Enable Global Interrupts
}

void TIMER0_SetCallback(void (*callback)(void)) {
    timer_callback = callback;
}

void interrupt() {
    if (T0IF_bit) {       // Check Timer0 flag
        TMR0 = 178;       // Reload for next 10ms

        if (timer_callback != 0) {
            timer_callback();
        }

        T0IF_bit = 0;     // Clear flag
    }
}