#include "Timer_interface.h"
#include "../../SERVICES/BIT_MATH.h"

/* Static global pointer for the callback */
static void (*TMR0_Callback)(void) = 0;

void TMR0_Init(void) {
    /* 1. Internal instruction cycle clock (Fosc/4) */
    CLR_BIT(OPTION_REG, T0CS);

    /* 2. Assign Prescaler to Timer0 */
    CLR_BIT(OPTION_REG, PSA);

    /* 3. Set Prescaler to 1:32 (PS2:PS0 = 100) */
    SET_BIT(OPTION_REG, PS2);
    CLR_BIT(OPTION_REG, PS1);
    CLR_BIT(OPTION_REG, PS0);

    /* 4. Preload TMR0 for 1ms interval */
    TMR0 = 6;
}

void TMR0_Enable(void) {
    SET_BIT(INTCON, GIE);    /* Global Interrupt Enable */
    SET_BIT(INTCON, TMR0IE); /* Timer0 Overflow Interrupt Enable */
}

void TMR0_Disable(void) {
    CLR_BIT(INTCON, TMR0IE);
}

void TMR0_SetCallback(void (*ptr)(void)) {
    TMR0_Callback = ptr;
}

/* Single Interrupt entry point for mikroC */
void Timer0_ISR_Logic(void) {
    if (TMR0IF_bit) {
        TMR0 = 6;

        if (TMR0_Callback != 0) {
            TMR0_Callback();
        }

        TMR0IF_bit = 0; /* Clear Flag */
    }
}