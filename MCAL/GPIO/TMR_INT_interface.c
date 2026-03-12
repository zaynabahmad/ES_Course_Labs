#include "TMR_INT_interface.h"
#include "../../SERVICES/BIT_MATH.h"

void TMR_INT_Init(void) {
    TMR0 = 0;
    CLR_BIT(INTCON, TMR0IF_BIT);
    CLR_BIT(INTCON, TMR0IE_BIT);
}

void TMR_INT_Enable(void) {
    SET_BIT(INTCON, TMR0IE_BIT);
    SET_BIT(INTCON, GIE_BIT);
    CLR_BIT(INTCON, TMR0IF_BIT);
    // Removed hardcoded OPTION_REG assignment to preserve Timer0_Init settings
}

void TMR_INT_Disable(void) {
    CLR_BIT(INTCON, TMR0IE_BIT);
    CLR_BIT(INTCON, TMR0IF_BIT);
}

void TMR_INT_SetPreload(u8 preload_value) {
    TMR0 = preload_value;
}

void TMR_INT_SetPrescaler(u8 prescaler_value) {
    OPTION_REG &= 0xF8;               // Clear bits 0, 1, 2
    OPTION_REG |= (prescaler_value & 0x07); // Set new prescaler
    CLR_BIT(OPTION_REG, PSA_BIT);     // Assign to Timer0
    CLR_BIT(OPTION_REG, TOCS_BIT);    // Internal Clock
}

void set_tmr0(u8 value) {
    TMR0 = value;
}