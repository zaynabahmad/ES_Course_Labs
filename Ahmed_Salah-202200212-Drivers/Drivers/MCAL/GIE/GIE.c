#include "../../SERVICES/Bit_Math.h"
#include "GIE.h"

#define INTCON    *((volatile u8*)0x0B)

void M_GIE_voidEnable(void) {
    SET_BIT(INTCON, 7); // GIE = 1
}

void M_GIE_voidDisable(void) {
    CLR_BIT(INTCON, 7); // GIE = 0
}