#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"

/* Global pointer to function for Callback */
static void (*EXT_INT_pvCallBackFunc)(void) = NULL_PTR;

void EXT_INT_voidInit(void) {
    /* Set Default Edge: Falling */
    CLR_BIT(OPTION_REG, INTEDG_BIT);
    /* Clear Flag */
    CLR_BIT(INTCON_REG, INTF_BIT);
}

void EXT_INT_voidSetEdge(u8 Copy_u8Edge) {
    if (Copy_u8Edge == EXT_INT_RISING_EDGE) SET_BIT(OPTION_REG, INTEDG_BIT);
    else CLR_BIT(OPTION_REG, INTEDG_BIT);
}

void EXT_INT_voidEnable(void) {
    SET_BIT(INTCON_REG, INTE_BIT);
    SET_BIT(INTCON_REG, GIE_BIT);
}

void EXT_INT_voidSetCallback(void (*Copy_pvCallBackFunc)(void)) {
    EXT_INT_pvCallBackFunc = Copy_pvCallBackFunc;
}

/* Interrupt Service Routine - This name is compiler specific,
   but the logic inside follows our architecture */
void interrupt ISR(void) {
    if (GET_BIT(INTCON_REG, INTF_BIT) == 1) {
        if (EXT_INT_pvCallBackFunc != NULL_PTR) {
            EXT_INT_pvCallBackFunc();
        }
        CLR_BIT(INTCON_REG, INTF_BIT); // Clear Flag
    }
}