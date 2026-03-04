#include "EXT_INT0.h"
#include "../Services Layer/Std_Types.h"

static PtrToFunc INT0_CallBack = 0;

void EXT_INT0_Init(void) {
    TRISB0_bit = 1;
    INTF_bit = 0;
}

void EXT_INT0_Enable(void) {
    GIE_bit = 1;
    INTE_bit = 1;
}

void EXT_INT0_Disable(void) {
    INTE_bit = 0;
}

void EXT_INT0_SetEdge(uint8 edge_type) {
    if (edge_type == RISING_EDGE) {
        INTEDG_bit = 1;
    } else {
        INTEDG_bit = 0;
    }
}

void EXT_INT0_SetCallback(PtrToFunc ptr) {
    INT0_CallBack = ptr;
}


void interrupt() {
    if (INTF_bit == 1) {
        if (INT0_CallBack != 0) {
            INT0_CallBack();
        }
        INTF_bit = 0;
    }
}