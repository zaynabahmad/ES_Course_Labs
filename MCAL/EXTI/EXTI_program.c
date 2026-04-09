#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

void EXTI_voidInit(u8 copy_u8Edge) {
    /* Set Edge: Bit 6 of OPTION_REG (INTEDG) */
    if(copy_u8Edge == EXTI_RISING_EDGE) SET_BIT(OPTION_REG, 6);
    else CLR_BIT(OPTION_REG, 6);

    /* Clear Flag: Bit 1 of INTCON (INTF) */
    CLR_BIT(INTCON_REG, 1);
}

void EXTI_voidEnable(void) {
    /* (GIE) and (INTE) [External and glohal interrupts] */
    SET_BIT(INTCON_REG, 7);
    SET_BIT(INTCON_REG, 4);
}