#include "EXT_INT0_INTERFACE.h"
#include "EXT_INT0_PRIVATE.h"
#include "../../SERVICES/BIT_MATH.h"

void (*EXT_INT0_Callback)(void) = NULL_PTR;

void EXT_INT0_Init(void) {
    SET_BIT(TRISB, 0);
    CLR_BIT(INTCON, 1);
}

void EXT_INT0_Enable(void) {
    SET_BIT(INTCON, 4);
    SET_BIT(INTCON, 7);
}

void EXT_INT0_Disable(void) {
    CLR_BIT(INTCON, 4);
}

void EXT_INT0_SetEdge(u8 edge_type) {
    if(edge_type == RISING_EDGE)
        SET_BIT(OPTION_REG, 6);
    else
        CLR_BIT(OPTION_REG, 6);
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    EXT_INT0_Callback = ptr;
}

void interrupt() {
    if(GET_BIT(INTCON, 1) == 1) {
        if(EXT_INT0_Callback != NULL_PTR) {
            EXT_INT0_Callback();
        }
        CLR_BIT(INTCON, 1);
    }
}