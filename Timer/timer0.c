// timer1.c - Using Timer1 (more reliable in MikroC PRO)
#include "timer0.h"

void Timer1_Init(void) {
    T1CON = 0x31;  // Timer1 on, 1:8 prescaler, internal clock
}

void Timer1_Start(void) {
    T1CONbits.TMR1ON = 1;
}

void Timer1_Stop(void) {
    T1CONbits.TMR1ON = 0;
}

void Timer1_SetDelayMs(uint16 delay_ms) {
    // For 1ms delay at 8MHz with 1:8 prescaler
    // 8MHz/4 = 2MHz instruction cycle = 0.5us
    // 0.5us * 8 prescaler = 4us per count
    // Need 250 counts for 1ms
    uint16 timer_value = 65536 - (250 * delay_ms);
    TMR1H = timer_value >> 8;
    TMR1L = timer_value & 0xFF;
}

void Timer1_ClearFlag(void) {
    TMR1IF = 0;
}

uint8 Timer1_IsOverflow(void) {
    return TMR1IF;
}