#include "timer0.h"
#include "../../Common/bit_math.h"

static void (*g_timerCallback)(void) = NULL;

void TIMER0_Init(void) {
    // Assuming 8MHz Crystal, 1ms Tick:
    // Prescaler 1:8, TMR0 start value = 6 (for 250 counts)
    OPTION_REG &= 0xD0; // Clear PSA and PS bits
    OPTION_REG |= 0x02; // Prescaler 1:8
    TMR0 = 6;           // Load 250 counts
    
    INTCON.TMR0IE = 1;  // Enable Timer0 Interrupt
    INTCON.GIE = 1;     // Global Interrupt Enable
}

void TIMER0_SetCallback(void (*ptr)(void)) {
    if (ptr != NULL) g_timerCallback = ptr;
}

// Updated ISR to handle both External INT and Timer0
void interrupt() {
    // Handle External Interrupt (Existing)
    if (INTCON.INTF == 1) {
        // ... (Your existing EXT_INT0 code)
        INTCON.INTF = 0;
    }
    
    // Handle Timer0 Interrupt (New)
    if (INTCON.TMR0IF == 1) {
        if (g_timerCallback != NULL) {
            g_timerCallback();
        }
        TMR0 = 6;         // Reload for 1ms
        INTCON.TMR0IF = 0; // Clear flag
    }
}