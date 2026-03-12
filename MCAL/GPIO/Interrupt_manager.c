#include "Interrupt_manager.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TMR_INT_Callback)(void) = 0;
static void (*EXT_INT_Callback)(void) = 0;

volatile u16 TMR0_Counter = 0;
extern volatile u16 target_overflows;

void TMR_INT_SetCallback(void (*ptr)(void)) { if (ptr) TMR_INT_Callback = ptr; }
void EXT_INT_SetCallback(void (*ptr)(void)) { if (ptr) EXT_INT_Callback = ptr; }

void interrupt() {
    // Timer0 logic
    if (GET_BIT(INTCON, TMR0IF_BIT) && GET_BIT(INTCON, TMR0IE_BIT)) {
        TMR0_Counter++;
        if (TMR0_Counter >= target_overflows) {
            TMR0_Counter = 0;
            if (TMR_INT_Callback) TMR_INT_Callback();
        }
        CLR_BIT(INTCON, TMR0IF_BIT);
    }
    // External logic (RB0)
    if (GET_BIT(INTCON, INTF_BIT) && GET_BIT(INTCON, INTE_BIT)) {
        if (EXT_INT_Callback) EXT_INT_Callback();
        CLR_BIT(INTCON, INTF_BIT);
    }
}