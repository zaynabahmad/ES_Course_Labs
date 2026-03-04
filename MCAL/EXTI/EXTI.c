#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global pointer to hold the callback function address */
static void (*EXTI_CallBack)(void) = NULL_PTR;

void EXTI_Int0Init(void) {
    /* Enable Global Interrupts */
    SET_BIT(INTCON_REG, GIE);
    /* Enable External Interrupt on RB0 */
    SET_BIT(INTCON_REG, INTE);
}

void EXTI_Int0SetEdge(u8 Edge) {
    if(Edge == EXTI_RISING_EDGE)
        SET_BIT(OPTION_REG_REG, INTEDG);
    else
        CLR_BIT(OPTION_REG_REG, INTEDG);
}

void EXTI_Int0SetCallBack(void (*LocalPtr)(void)) {
    EXTI_CallBack = LocalPtr;
}

/* ISR (Interrupt Service Routine) for mikroC */
void interrupt() {
    if(GET_BIT(INTCON_REG, INTF) == 1) {
        if(EXTI_CallBack != NULL_PTR) {
            EXTI_CallBack();
        }
        /* Clear the flag so the interrupt can fire again */
        CLR_BIT(INTCON_REG, INTF);
    }
}