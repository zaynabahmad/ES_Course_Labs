/**
 * @file    timer0.c
 * @brief   PIC16F877 Timer0 Driver Implementation
 */

#include "timer0.h"

/* Store preload for auto-reload in ISR / polling */
static uint8_t s_preload = 0x00u;

/*------------------------------------------------------------
 * TIMER0_Init
 *------------------------------------------------------------*/
void TIMER0_Init(const TIMER0_Config_t *cfg)
{
    s_preload = cfg->preloadVal;

    /* Build OPTION_REG — preserve RBPU and INTEDG bits */
    uint8_t opt = OPTION_REG;

    /* T0CS (bit5) — clock source */
    if (cfg->clkSrc == TIMER0_CLK_T0CKI) {
        opt |= (uint8_t)(1u << 5);
    } else {
        opt &= (uint8_t)~(1u << 5);
    }

    /* T0SE (bit4) — external edge */
    if (cfg->extEdge == TIMER0_EDGE_FALLING) {
        opt |= (uint8_t)(1u << 4);
    } else {
        opt &= (uint8_t)~(1u << 4);
    }

    /* PSA (bit3) — prescaler assignment */
    if (cfg->psAssign == TIMER0_PS_WDT) {
        opt |= (uint8_t)(1u << 3);
    } else {
        opt &= (uint8_t)~(1u << 3);
        /* PS<2:0> (bits2:0) */
        opt &= (uint8_t)~0x07u;
        opt |= (uint8_t)(cfg->psRate & 0x07u);
    }

    OPTION_REG = opt;

    /* Preload timer */
    TMR0 = s_preload;

    /* Interrupt setup */
    INTCONbits.T0IF = 0;  /* Clear flag */
    if (cfg->intEnable == TIMER0_INT_ENABLE) {
        INTCONbits.T0IE = 1;
    }
}

/*------------------------------------------------------------
 * TIMER0_Start
 *------------------------------------------------------------*/
void TIMER0_Start(void)
{
    /* Switch to internal clock → timer begins counting */
    OPTION_REGbits.T0CS = 0;
    TMR0 = s_preload;
    INTCONbits.T0IF = 0;
}

/*------------------------------------------------------------
 * TIMER0_Stop
 * PIC16F877 has no dedicated stop bit for Timer0.
 * Freeze counting by switching to external clock (T0CS=1)
 * so no transitions are seen on the unused pin.
 *------------------------------------------------------------*/
void TIMER0_Stop(void)
{
    OPTION_REGbits.T0CS = 1;  /* External — stops incrementing */
}

/*------------------------------------------------------------
 * TIMER0_SetPreload
 *------------------------------------------------------------*/
void TIMER0_SetPreload(uint8_t value)
{
    s_preload = value;
    TMR0 = s_preload;
}

/*------------------------------------------------------------
 * TIMER0_GetCount
 *------------------------------------------------------------*/
uint8_t TIMER0_GetCount(void)
{
    return TMR0;
}

/*------------------------------------------------------------
 * TIMER0_ClearFlag
 *------------------------------------------------------------*/
void TIMER0_ClearFlag(void)
{
    INTCONbits.T0IF = 0;
}

/*------------------------------------------------------------
 * TIMER0_GetFlag
 *------------------------------------------------------------*/
uint8_t TIMER0_GetFlag(void)
{
    return (uint8_t)INTCONbits.T0IF;
}

/*------------------------------------------------------------
 * TIMER0_EnableInterrupt / DisableInterrupt
 *------------------------------------------------------------*/
void TIMER0_EnableInterrupt(void)
{
    INTCONbits.T0IF = 0;
    INTCONbits.T0IE = 1;
}

void TIMER0_DisableInterrupt(void)
{
    INTCONbits.T0IE = 0;
}

/*------------------------------------------------------------
 * TIMER0_DelayOverflows (polling, GIE must be 0)
 *------------------------------------------------------------*/
void TIMER0_DelayOverflows(uint8_t overflows)
{
    uint8_t i;
    for (i = 0u; i < overflows; i++) {
        TMR0 = s_preload;
        INTCONbits.T0IF = 0;
        while (INTCONbits.T0IF == 0) {
            /* Wait for overflow */
        }
    }
    INTCONbits.T0IF = 0;
}

/*------------------------------------------------------------
 * Weak callback
 *------------------------------------------------------------*/
void __attribute__((weak)) TIMER0_OVF_Callback(void)
{
    /* User implements this */
}

/*============================================================
 * ISR dispatch (shared; include only once per project)
 * If using the EXTI driver, merge the ISR bodies into one.
 *============================================================*/
#ifdef TIMER0_USE_STANDALONE_ISR
void __interrupt() TIMER0_ISR(void)
{
    if (INTCONbits.T0IE && INTCONbits.T0IF) {
        TMR0 = s_preload;          /* Auto-reload */
        INTCONbits.T0IF = 0;
        TIMER0_OVF_Callback();
    }
}
#endif
