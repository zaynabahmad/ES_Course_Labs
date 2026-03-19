#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

// External references to your driver logic
extern void Timer0_ISR_Logic(void);
extern void EXT_INT0_ISR_Logic(void);

void interrupt() {
    // 1. Check Timer0 Interrupt
    if (TMR0IF_bit) {
        Timer0_ISR_Logic(); // Call the logic sitting in Timer.c
        TMR0IF_bit = 0;     // Clear flag
    }

    // 2. Check External Interrupt (INT0)
    if (INTF_bit) {
        EXT_INT0_ISR_Logic(); // Call the logic sitting in EXT_INT.c
        INTF_bit = 0;         // Clear flag
    }
}