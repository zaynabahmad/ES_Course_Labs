#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "exti0_interface.h"

static void (*G_EXTI0_Callback)(void) = 0;

void MEXTI0_vInit(void) {
    TRISB0_bit = 1;   // RB0 as Input
    INTEDG_bit = 1;   // Rising Edge
    INTE_bit   = 1;   // Enable INT0
    GIE_bit    = 1;   // Global Interrupt Enable
}

void MEXTI0_vSetCallback(void (*ptr)(void)) {
    G_EXTI0_Callback = ptr;
}

/* MikroC Specific ISR Syntax */
void interrupt() {
    if (INTF_bit == 1) {
        if (G_EXTI0_Callback != 0) {
            G_EXTI0_Callback();
        }
        INTF_bit = 0; // Clear Flag
    }
}