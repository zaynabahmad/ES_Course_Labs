#include "../EXTINT/EXTINT_interface.h"
#include "../TIMER0/Timer0_interface.h"
#include "../MCU_Registers.h"
#include "../../SERVICES/BIT_MATH.h"

void interrupt() {
        if (GET_BIT(INTCON, INTF)) {
                EXT_INT_ISR_Handler();
        }
        else if (GET_BIT(INTCON, TMR0IF) == 1) {
                TMR0_ISR_Handler();
        }
}