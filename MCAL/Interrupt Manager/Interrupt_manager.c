#include "Interrupt_manager.h"

/* Global function pointers for callbacks */
static void (*TMR_INT_Callback)(void) = 0;
static void (*EXT_INT_Callback)(void) = 0;

/* Timer0 counting variables */
volatile u16 TMR0_Counter = 0;
volatile u16 target_overflows = 0;


void TMR_INT_SetCallback(void (*ptr)(void)) {
    if (ptr) TMR_INT_Callback = ptr;
}

void EXT_INT_SetCallback(void (*ptr)(void)) {
    if (ptr) EXT_INT_Callback = ptr;
}

void interrupt() {
    // Check if Timer0 overflow interrupt occurred and is enabled
    if (GET_BIT(INTCON, TMR0IF_BIT) && GET_BIT(INTCON, TMR0IE_BIT)) {
        TMR0 = 0;           //Reset Timer0 count to 0 for next cycle
        TMR0_Counter++;     // increment overflow counter

        // Call callback when target overflows reached
        if (TMR0_Counter >= target_overflows) {
            TMR0_Counter = 0;       // reset counter
            if (TMR_INT_Callback) {
                TMR_INT_Callback(); // fire Timer0 callback
            }
        }
        
        CLR_BIT(INTCON, TMR0IF_BIT); // clear Timer0 interrupt flag
    }

    // Check if External interrupt occurred and is enabled
    if (GET_BIT(INTCON, INTF_BIT) && GET_BIT(INTCON, INTE_BIT)) {

        if (EXT_INT_Callback) {
            EXT_INT_Callback();      // fire External interrupt callback
        }

        CLR_BIT(INTCON, INTF_BIT);   // clear INT0 interrupt flag
    }
}

