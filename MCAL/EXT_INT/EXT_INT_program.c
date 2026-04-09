#ifndef __XC8
#define __interrupt()
#endif
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"

/* Global pointer for Callback */
static void (*EXTI0_CallBack)(void) = NULL_PTR;

void EXT_INT0_Init(void) {
    CLR_BIT(INTCON, 4); // INTE = 0

    /* Set RB0 as input */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* Default: Falling Edge */
    SET_BIT(OPTION_REG, 6); // INTEDG = 1

    /* Clear Flag */
    CLR_BIT(INTCON, 1); // INTF = 0
}

void EXT_INT0_Enable(void) {
    SET_BIT(INTCON, 4); // INTE = 1
    SET_BIT(INTCON, 7); // GIE = 1
}

void EXT_INT0_SetEdge(u8 edge_type) {
    if (edge_type == 1) /* Falling */
        SET_BIT(OPTION_REG, 6);
    else               /* Rising */
        CLR_BIT(OPTION_REG, 6);
}

void EXT_INT0_SetCallback(void (*LocalPtr)(void)) {
    EXTI0_CallBack = LocalPtr;
}

void __interrupt() ISR(void) {
    if (GET_BIT(INTCON, 1) == 1) {
        if (EXTI0_CallBack != NULL_PTR) {
            EXTI0_CallBack();
        }
        CLR_BIT(INTCON, 1);
    }
}