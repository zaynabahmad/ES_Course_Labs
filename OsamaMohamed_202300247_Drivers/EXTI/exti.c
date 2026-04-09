/*
 * exti.c
 * External Interrupt Driver for PIC16F877A
 */

#include "exti.h"
#include "../common_macros.h"

void EXTI_init(EXTI_Source src, EXTI_Edge edge) {
    if (src == EXTI_INT_PIN) {
        TRISBbits.TRISB0 = 1;   /* RB0 as input */

        /* Edge select: INTEDG bit in OPTION_REG
           1 = Rising edge, 0 = Falling edge      */
        if (edge == EXTI_RISING_EDGE)
            OPTION_REGbits.INTEDG = 1;
        else
            OPTION_REGbits.INTEDG = 0;

        INTCONbits.INTF   = 0;   /* Clear flag  */
        INTCONbits.INTE   = 1;   /* Enable INT  */

    } else { /* EXTI_RB_CHANGE */
        /* RB4-RB7 as inputs */
        TRISB |= 0xF0;
        INTCONbits.RBIF = 0;    /* Clear flag  */
        INTCONbits.RBIE = 1;    /* Enable RBIE */
    }

    INTCONbits.GIE = 1;         /* Global interrupt enable */
}

void EXTI_enable(EXTI_Source src) {
    if (src == EXTI_INT_PIN)
        INTCONbits.INTE = 1;
    else
        INTCONbits.RBIE = 1;
}

void EXTI_disable(EXTI_Source src) {
    if (src == EXTI_INT_PIN)
        INTCONbits.INTE = 0;
    else
        INTCONbits.RBIE = 0;
}
