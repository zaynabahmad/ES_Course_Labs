#include "ext_int0.h"
#include "ext_int0_cfg.h"
#include "../../Common/bit_math.h"

// Private global pointer for the callback function
static void (*g_pCallback)(void) = NULL;

void EXT_INT0_Init(void) {
    TRISB.F0 = 1;        // RB0 is input
    INTCON.INTE = 0;     // Initially disabled
    INTCON.INTF = 0;     // Clear flag
    
    // Apply configuration from ext_int0_cfg.h
    #if EXT_INT0_EDGE_TYPE == EXT_INT0_RISING_EDGE
        OPTION_REG.INTEDG = 1;
    #else
        OPTION_REG.INTEDG = 0;
    #endif
}

void EXT_INT0_Enable(void) {
    INTCON.GIE = 1;      // Global Enable
    INTCON.INTE = 1;     // External Enable
}

void EXT_INT0_Disable(void) {
    INTCON.INTE = 0;
}

void EXT_INT0_SetEdge(uint8 edge_type) {
    if(edge_type == EXT_INT0_RISING_EDGE) OPTION_REG.INTEDG = 1;
    else OPTION_REG.INTEDG = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    if (ptr != NULL) g_pCallback = ptr;
}

// ISR - Hardware specific
void interrupt() {
    if (INTCON.INTF == 1) {
        if (g_pCallback != NULL) {
            g_pCallback(); // Jump to Application function
        }
        INTCON.INTF = 0;   // Clear flag
    }
}