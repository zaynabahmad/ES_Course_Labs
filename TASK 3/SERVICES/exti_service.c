#include "STD_TYPES.h"
#include "BIT_MATH.h"


void EXTI_vEnableGlobalInterrupts(void) {
    /* Set GIE bit in INTCON register */
    *((volatile uint8*)0x0B) |= (1 << 7);
}

void EXTI_vDisableGlobalInterrupts(void) {
    /* Clear GIE bit in INTCON register */
    *((volatile uint8*)0x0B) &= ~(1 << 7);
}