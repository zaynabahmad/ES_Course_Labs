#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER0_CallBack)(void) = NULL_PTR;
static u8 TMR0_Overflows = 0;

void TIMER0_Init(void) {
    /* Select internal clock source (Fosc/4) */
    CLR_BIT(OPTION_REG_REG, 5); // T0CS = 0

    /* Assign Prescaler to Timer0 */
    CLR_BIT(OPTION_REG_REG, 3); // PSA = 0

    /* Set Prescaler to 1:256 (PS2:PS0 = 111) */
    SET_BIT(OPTION_REG_REG, 2);
    SET_BIT(OPTION_REG_REG, 1);
    SET_BIT(OPTION_REG_REG, 0);

    /* Load Preload for ~20ms overflow (At 8MHz Fosc)
       Preload 100 -> 156 counts -> 156 * 128us = 19.968ms */
    TMR0_REG = 100;
    TMR0_Overflows = 0;

    /* Enable Timer0 Interrupt */
    SET_BIT(INTCON_REG, 5); // TMR0IE
    SET_BIT(INTCON_REG, 7); // GIE
}

void TIMER0_SetCallBack(void (*LocalPtr)(void)) {
    TIMER0_CallBack = LocalPtr;
}

void TIMER0_ISR_Handler(void) {
    TMR0_REG = 100; // Reload timer
    TMR0_Overflows++;

    /* 50 overflows * 19.968ms ≈ 1000ms (1 Second) */
    if (TMR0_Overflows >= 50) {
        TMR0_Overflows = 0;
        if(TIMER0_CallBack != NULL_PTR) {
            TIMER0_CallBack();
        }
    }
}
