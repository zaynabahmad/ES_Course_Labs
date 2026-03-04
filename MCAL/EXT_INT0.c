#include "EXT_INT0.h"

static void (*INT0_Callback)(void) = 0;

void EXT_INT0_Init(void) {
    TRISB0_bit = 1;  // Configure RB0 as Input for Interrupt
    INTF_bit = 0;    // Clear flag
    EXT_INT0_SetEdge(EXT_INT0_DEFAULT_EDGE); 
}

void EXT_INT0_Enable(void) {
    INTE_bit = 1; 
    GIE_bit = 1;  
}

void EXT_INT0_Disable(void) {
    INTE_bit = 0; 
}

void EXT_INT0_SetEdge(uint8 edge_type) {
    if (edge_type == INT0_RISING_EDGE) OPTION_REG.INTEDG = 1;
    else OPTION_REG.INTEDG = 0;
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    INT0_Callback = ptr; 
}

void interrupt(void) {
    if (INTF_bit == 1) { 
        INTF_bit = 0; // Clear flag immediately
        if (INT0_Callback != 0) {
            INT0_Callback(); 
        }
    }
}