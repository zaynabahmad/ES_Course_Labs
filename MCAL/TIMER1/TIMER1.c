#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*TIMER1_CallBack)(void) = NULL_PTR;

void TIMER1_Init(void) {
    /* Set Timer1 Clock Source to Internal (Fosc/4) */
    CLR_BIT(T1CON_REG, 1); // TMR1CS = 0

    /* Set Prescaler to 1:8 (T1CKPS1:T1CKPS0 = 11) */
    SET_BIT(T1CON_REG, 5);
    SET_BIT(T1CON_REG, 4);

    /* Load Preload for 200ms (At 8MHz Fosc)
       200ms / 4us tick = 50,000 counts.
       Preload = 65536 - 50000 = 15536 = 0x3CB0 */
    TMR1H_REG = 0x3C;
    TMR1L_REG = 0xB0;

    /* Enable Timer1 Interrupt */
    SET_BIT(PIE1_REG, 0);   // TMR1IE
    SET_BIT(INTCON_REG, 6); // PEIE (Peripheral Interrupt Enable)
    SET_BIT(INTCON_REG, 7); // GIE

    /* Turn ON Timer1 */
    SET_BIT(T1CON_REG, 0);  // TMR1ON
}

void TIMER1_SetCallBack(void (*LocalPtr)(void)) {
    TIMER1_CallBack = LocalPtr;
}

void TIMER1_ISR_Handler(void) {
    /* Reload Preload for next 200ms */
    TMR1H_REG = 0x3C;
    TMR1L_REG = 0xB0;

    if(TIMER1_CallBack != NULL_PTR) {
        TIMER1_CallBack();
    }
}
