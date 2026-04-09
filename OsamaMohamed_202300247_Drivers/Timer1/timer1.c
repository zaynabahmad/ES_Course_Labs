/*
 * timer1.c
 * Timer1 Driver for PIC16F877A
 */

#include "timer1.h"
#include "../common_macros.h"

static void (*g_timer1Callback)(void) = NULL;
static uint16 g_preload = 0;

/* ---- ISR is defined in the application file ---- */
/* The application must call Timer1_ISR_Handler() from its __interrupt() */
void Timer1_ISR_Handler(void) {
    if (PIR1bits.TMR1IF) {
        PIR1bits.TMR1IF = 0;            /* Clear overflow flag      */
        TMR1H = (uint8)(g_preload >> 8);/* Reload preload value     */
        TMR1L = (uint8)(g_preload);
        if (g_timer1Callback)
            g_timer1Callback();
    }
}

void Timer1_init(const Timer1_Config *config) {
    g_preload = config->preloadValue;

    /* Stop timer, set prescaler */
    T1CON = 0x00;
    T1CONbits.T1CKPS1 = (config->prescaler >> 1) & 1;
    T1CONbits.T1CKPS0 = (config->prescaler)      & 1;

    /* Preload */
    TMR1H = (uint8)(config->preloadValue >> 8);
    TMR1L = (uint8)(config->preloadValue);

    /* Interrupt */
    if (config->enableInt) {
        PIR1bits.TMR1IF = 0;
        PIE1bits.TMR1IE = 1;
        INTCONbits.PEIE = 1;  /* Peripheral interrupt enable */
        INTCONbits.GIE  = 1;  /* Global interrupt enable     */
    }

    /* Start timer (internal clock, TMR1CS=0) */
    T1CONbits.TMR1ON = 1;
}

void Timer1_deInit(void) {
    T1CONbits.TMR1ON = 0;
    PIE1bits.TMR1IE  = 0;
    PIR1bits.TMR1IF  = 0;
    TMR1H = 0;
    TMR1L = 0;
}

void Timer1_setPreload(uint16 value) {
    g_preload = value;
    TMR1H = (uint8)(value >> 8);
    TMR1L = (uint8)(value);
}

void Timer1_setCallBack(void (*ptr)(void)) {
    g_timer1Callback = ptr;
}
