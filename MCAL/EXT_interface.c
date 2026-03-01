#include "EXT_interface.h"
#include "STD_TYPES.h"

static void (*EXT_INT0_Callback)(void) = NULL;

void EXT_INT0_Init(void) {
    TRISB0_bit = 1;  // Set RB0 as input [cite: 6, 7]
    INTF_bit = 0;    // Clear flag [cite: 8]
}

void EXT_INT0_Enable(void) {
    INTE_bit = 1;    // Enable INT0 [cite: 9]
    GIE_bit = 1;     // Global interrupt enable [cite: 10]
}

void EXT_INT0_Disable(void) {
    INTE_bit = 0;    // [cite: 11]
}

void EXT_INT0_SetEdge(uint8 edge_type) {
    if(edge_type == EXT_INT0_RISING_EDGE)
        INTEDG_bit = 1; // [cite: 12]
    else
        INTEDG_bit = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    EXT_INT0_Callback = ptr; // [cite: 13]
}

void interrupt(void) {
    if(INTF_bit) {
        INTF_bit = 0; // Clear flag [cite: 14]
        if(EXT_INT0_Callback != NULL) {
            EXT_INT0_Callback(); // [cite: 15]
        }
    }
}