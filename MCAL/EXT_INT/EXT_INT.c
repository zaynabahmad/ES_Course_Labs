 #include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "EXT_INT_interface.h"

// Pointer to function for callback
static void (*INT0_Callback)(void) = 0;

void EXT_INT0_Init(void) {
    // RB0/INT0 is input
    SET_BIT(TRISB, 0);
    // Clear flag initially
    CLR_BIT(INTCON, INTF);
}

void EXT_INT0_Enable(void) {
    SET_BIT(INTCON, GIE);  // Global Interrupt Enable
    SET_BIT(INTCON, INTE); // INT0 External Interrupt Enable
}

void EXT_INT0_Disable(void) {
    CLR_BIT(INTCON, INTE);
}

void EXT_INT0_SetEdge(u8 edge_type) {
    if(edge_type == RISING_EDGE) SET_BIT(OPTION_REG, INTEDG);
    else CLR_BIT(OPTION_REG, INTEDG);
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    INT0_Callback = ptr;
}

// ISR implementation inside MCAL
void interrupt() {
    if(GET_BIT(INTCON, INTF)) {
        if(INT0_Callback != 0) {
            INT0_Callback(); // Call the Application function
        }
        CLR_BIT(INTCON, INTF); // Clear flag
    }
}