#include "../../SERVICES/std_types.h"
#include "D:/ES-Project-Lab/SERVICES/bit_math.h"
#include "exti_prv.h"
#include "exti_interface.h"

// Global pointer to function for callback
static void (*EXTI_CallBackPtr)(void) = NULL;

void EXTI_init(u8 edge) {
    // Enable Global Interrupts
    SET_BIT(INTCON_REG, GIE);

    // Enable External Interrupt (INTE)
    SET_BIT(INTCON_REG, INTE);

    // Set Edge
    if(edge == EXTI_RISING_EDGE) {
        SET_BIT(OPTION_REG, INTEDG);
    } else {
        CLR_BIT(OPTION_REG, INTEDG);
    }
}

void EXTI_setCallback(void (*ptr)(void)) {
    if(ptr != NULL) {
        EXTI_CallBackPtr = ptr;
    }
}


// Flags
volatile u8 exti_flag = 0;
volatile u8 timer0_flag = 0;


// ================= ISR =================
void interrupt() {

    // EXTI
    if (GET_BIT(INTCON_REG, INTF) == 1) {
        exti_flag = 1;
        CLR_BIT(INTCON_REG, INTF);
    }

    // TIMER0
    if (GET_BIT(INTCON_REG, TMR0IF) == 1) {
        timer0_flag = 1;
        CLR_BIT(INTCON_REG, TMR0IF);
    }
}