#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"

static void (*TIMER0_CallBack)(void) = NULL_PTR;

void TIMER0_voidInit(void) {
    /* Internal Clock, Prescaler 1:256 */
    CLR_BIT(OPTION_REG, 5); // T0CS: Internal
    CLR_BIT(OPTION_REG, 3); // PSA: Assign to TMR0
    SET_BIT(OPTION_REG, 0); // PS0
    SET_BIT(OPTION_REG, 1); // PS1
    SET_BIT(OPTION_REG, 2); // PS2

    SET_BIT(INTCON, 5); // TMR0IE: Enable Interrupt
    SET_BIT(INTCON, 7); // GIE: Enable Global
}

void TIMER0_voidSetPreload(u8 Copy_u8Value) {
    TMR0 = Copy_u8Value;
}

void TIMER0_voidSetCallback(void (*Copy_ptr)(void)) {
    TIMER0_CallBack = Copy_ptr;
}