#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL_PTR;

void TIMER0_voidInit(void) {
    /* Select Internal Instruction Cycle Clock */
    CLR_BIT(OPTION_REG_REG, T0CS_BIT);
    /* Assign Prescaler to Timer0 (Prescaler 1:256) */
    CLR_BIT(OPTION_REG_REG, PSA_BIT);
    SET_BIT(OPTION_REG_REG, 0);
    SET_BIT(OPTION_REG_REG, 1);
    SET_BIT(OPTION_REG_REG, 2);

    /* Enable Timer0 Interrupt */
    SET_BIT(INTCON_REG, TMR0IE_BIT);
}

void TIMER0_voidSetPreload(u8 Copy_u8Preload) {
    TMR0_REG = Copy_u8Preload;
}

void TIMER0_voidSetCallback(void (*Copy_pvCallBackFunc)(void)) {
    TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
}

/* Updated ISR logic to include Timer0 */
void interrupt ISR(void) {
    // Timer0 Overflow
    if (GET_BIT(INTCON_REG, TMR0IF_BIT) == 1) {
        if (TIMER0_pvCallBackFunc != NULL_PTR) {
            TIMER0_pvCallBackFunc();
        }
        CLR_BIT(INTCON_REG, TMR0IF_BIT);
    }
}