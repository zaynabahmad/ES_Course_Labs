#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../TMR0/TMR0_private.h"  //
//#include "EXTI_private.h"

/* Borrow the function pointers from the other drivers */
extern void (*TMR0_CallBackFuncP)(void);
//extern void (*EXTI_pvCallBackFunc)(void);

void interrupt() {
    /* 1. Timer0 Dispatcher */
    if (GET_BIT(INTCON, TMR0IF) == 1) {
         TMR0=100;
        CLR_BIT(INTCON,TMR0IF); // Clear Flag

        if (TMR0_CallBackFuncP != NULL_PTR) {
            TMR0_CallBackFuncP();
        }
    }

    /* 2. External Interrupt Dispatcher
    if (INTF_bit == 1) {
        INTF_bit = 0; // Clear Flag
        if (EXTI_pvCallBackFunc != NULL_PTR) {
            EXTI_pvCallBackFunc();
        }
    }
     */
}