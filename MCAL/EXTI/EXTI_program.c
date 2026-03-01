#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"

// Global pointer to function to hold the callback address
static void (*EXTI_pvCallBackFunc)(void) = NULL;

void EXTI_voidInit(void) {
    SET_BIT(OPTION_REG, 6);   // Rising edge

    // Clear the Interrupt Flag
    CLR_BIT(INTCON, 1);

    // Enable the External Interrupt (
    SET_BIT(INTCON, 4);     // INTE bit
}

void EXTI_voidSetCallBack(void (*Copy_pvCallBackFunc)(void)) {
    if (Copy_pvCallBackFunc != NULL) {
        EXTI_pvCallBackFunc = Copy_pvCallBackFunc;
    }
}

// The Interrupt Service Routine (ISR)

void interrupt(void) {
    if (GET_BIT(INTCON, 1) == 1) {
        if (EXTI_pvCallBackFunc != NULL) {
            EXTI_pvCallBackFunc();
        }

        CLR_BIT(INTCON, 1);
    }
}