/**
 * @file    exti.c
 * @brief   PIC16F877 External Interrupt Driver Implementation
 */

#include "exti.h"

/*============================================================
 * Weak callback definitions
 * Override these in application code — they compile to nothing
 * if not overridden (no-op stubs).
 *============================================================*/
void __attribute__((weak)) EXTI_INT_Callback(void)
{
    /* User implements this */
}

void __attribute__((weak)) EXTI_RBChange_Callback(void)
{
    /* User implements this — remember to read PORTB to clear mismatch */
}

/*------------------------------------------------------------
 * EXTI_INT_Init
 *------------------------------------------------------------*/
void EXTI_INT_Init(const EXTI_INT_Config_t *cfg)
{
    /* 1. Configure RB0 as input */
    TRISBbits.TRISB0 = 1;

    /* 2. Select trigger edge via INTEDG (OPTION_REG<6>) */
    OPTION_REGbits.INTEDG = (uint8_t)cfg->edge;

    /* 3. Clear the interrupt flag before enabling */
    INTCONbits.INTF = 0;

    /* 4. Enable INT interrupt enable bit */
    INTCONbits.INTE = 1;

    /* 5. Optionally enable global interrupts */
    if (cfg->globalIE == EXTI_ENABLE) {
        INTCONbits.GIE = 1;
    }
}

/*------------------------------------------------------------
 * EXTI_INT_Enable / Disable
 *------------------------------------------------------------*/
void EXTI_INT_Enable(void)
{
    INTCONbits.INTF = 0;   /* Clear flag before re-enabling */
    INTCONbits.INTE = 1;
}

void EXTI_INT_Disable(void)
{
    INTCONbits.INTE = 0;
}

/*------------------------------------------------------------
 * EXTI_INT_ClearFlag
 *------------------------------------------------------------*/
void EXTI_INT_ClearFlag(void)
{
    INTCONbits.INTF = 0;
}

/*------------------------------------------------------------
 * EXTI_INT_SetEdge
 *------------------------------------------------------------*/
void EXTI_INT_SetEdge(EXTI_Edge_t edge)
{
    OPTION_REGbits.INTEDG = (uint8_t)edge;
}

/*------------------------------------------------------------
 * EXTI_RBChange_Init
 *------------------------------------------------------------*/
void EXTI_RBChange_Init(EXTI_En_t globalIE)
{
    /* RB4:RB7 must be inputs for change notification */
    TRISB |= 0xF0u;

    /* Clear mismatch by reading PORTB, then clear flag */
    (void)PORTB;
    INTCONbits.RBIF = 0;

    /* Enable PORTB change interrupt */
    INTCONbits.RBIE = 1;

    if (globalIE == EXTI_ENABLE) {
        INTCONbits.GIE = 1;
    }
}

/*------------------------------------------------------------
 * EXTI_RBChange_Enable / Disable
 *------------------------------------------------------------*/
void EXTI_RBChange_Enable(void)
{
    (void)PORTB;
    INTCONbits.RBIF = 0;
    INTCONbits.RBIE = 1;
}

void EXTI_RBChange_Disable(void)
{
    INTCONbits.RBIE = 0;
}

/*------------------------------------------------------------
 * EXTI_RBChange_ClearFlag
 *------------------------------------------------------------*/
void EXTI_RBChange_ClearFlag(void)
{
    (void)PORTB;            /* Read to end mismatch condition */
    INTCONbits.RBIF = 0;
}

/*------------------------------------------------------------
 * Global interrupt helpers
 *------------------------------------------------------------*/
void EXTI_GlobalEnable(void)
{
    INTCONbits.GIE = 1;
}

void EXTI_GlobalDisable(void)
{
    INTCONbits.GIE = 0;
}

/*============================================================
 * ISR — place one ISR in the project; dispatch here
 * In MPLAB XC8 the ISR uses __interrupt() or the interrupt
 * keyword. Adapt as needed for your toolchain.
 *============================================================*/
void __interrupt() ISR(void)
{
    /* --- RB0/INT External Interrupt --- */
    if (INTCONbits.INTE && INTCONbits.INTF) {
        EXTI_INT_ClearFlag();
        EXTI_INT_Callback();
    }

    /* --- PORTB Change Interrupt --- */
    if (INTCONbits.RBIE && INTCONbits.RBIF) {
        EXTI_RBChange_ClearFlag();
        EXTI_RBChange_Callback();
    }
}
