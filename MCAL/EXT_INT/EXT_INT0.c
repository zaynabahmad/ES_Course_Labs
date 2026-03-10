#include "../../SERVICES/STD_TYPES.h"
#include "EXT_INT0_interface.h"
#include "EXT_INT0_config.h"

/* Global Pointer to Function (Callback Mechanism) */
static void (*EXT_INT0_Callback)(void) = 0; // NULL

void EXT_INT0_Init(void) {
    /* 1. Configure TRISB0 as input (INT0 pin) */
    TRISB0_bit = 1; 

    /* 2. Configure Edge based on config file (Bonus part) */
    #if EXT_INT0_SENSE_CONTROL == EXT_INT0_RISING_EDGE
        INTEDG_bit = 1;
    #elif EXT_INT0_SENSE_CONTROL == EXT_INT0_FALLING_EDGE
        INTEDG_bit = 0;
    #endif

    /* 3. Clear Interrupt Flag */
    INTF_bit = 0;
}

void EXT_INT0_Enable(void) {
    INTE_bit = 1; // Enable External Interrupt INT0
    GIE_bit  = 1; // Enable Global Interrupts
}

void EXT_INT0_Disable(void) {
    INTE_bit = 0; // Disable External Interrupt INT0
}

void EXT_INT0_SetEdge(u8 edge_type) {
    if (edge_type == EXT_INT0_RISING_EDGE) {
        INTEDG_bit = 1;
    } else if (edge_type == EXT_INT0_FALLING_EDGE) {
        INTEDG_bit = 0;
    }
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    if (ptr != 0) {
        EXT_INT0_Callback = ptr;
    }
}

/* ISR Implementation specific to mikroC */
void interrupt(void) {
    /* Check if the interrupt flag is set for INT0 */
    if (INTF_bit == 1) {
        /* Clear INTF flag to avoid recursive interrupts */
        INTF_bit = 0; 
        
        /* Execute the callback function if it was registered */
        if (EXT_INT0_Callback != 0) {
            EXT_INT0_Callback();
        }
    }
}