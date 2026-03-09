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

/* Removed MikroC's "interrupt" keyword to allow main.c to route it */
void EXTI_ISR_Handler(void) {
    if(EXTI_CallBack != NULL_PTR) {
        EXTI_CallBack();
    }
}
