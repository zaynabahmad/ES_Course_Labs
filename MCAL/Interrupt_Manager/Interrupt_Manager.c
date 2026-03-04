#include "../EXTINT/EXTINT_interface.h"
#include "../MCU_Registers.h"
#include "../../SERVICES/BIT_MATH.h"

void interrupt() {
        if (GET_BIT(INTCON, INTF)) {
                EXT_INT_ISR_Handler();
        }
}