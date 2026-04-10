#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "Timer0_private.h"
#include "Timer0_interface.h"

void TIMER0_voidInit(u8 copy_u8Prescaler) {
    /*  Set Timer Mode (T0CS = 0) */
    CLR_BIT(OPTION_REG, 5);

    /*  Assign Prescaler to Timer0 (PSA = 0) */
    CLR_BIT(OPTION_REG, 3);

    /*  Set Prescaler Value (Bits 2-0) */
    OPTION_REG &= 0xF8;
    OPTION_REG |= copy_u8Prescaler;
}

void TIMER0_voidSetPreload(u8 copy_u8Preload) {
    TMR0_REG = copy_u8Preload;
}

u8 TIMER0_u8GetTimerValue(void) {
    return TMR0_REG;
}
