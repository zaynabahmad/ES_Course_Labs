/*
 * timer1.h
 * Timer1 Driver for PIC16F877A
 *
 * Timer1 is a 16-bit timer/counter.
 * Overflow flag: TMR1IF (PIR1<0>)
 * Overflow interrupt enable: TMR1IE (PIE1<0>)
 *
 * Timer1 period formula (overflow):
 *   Toverflow = (65536 - preload) * prescaler * (4 / F_CPU)
 *
 * Example — 10 ms tick @ 8 MHz, prescaler=8:
 *   preload = 65536 - (0.01 * 8000000) / (4 * 8) = 65536 - 2500 = 63036 = 0xF63C
 */

#ifndef TIMER1_H
#define TIMER1_H

#include "../std_types.h"
#include <xc.h>

typedef enum {
    TIMER1_PRESCALER_1  = 0,
    TIMER1_PRESCALER_2  = 1,
    TIMER1_PRESCALER_4  = 2,
    TIMER1_PRESCALER_8  = 3
} Timer1_Prescaler;

typedef struct {
    Timer1_Prescaler prescaler;
    uint16           preloadValue;  /* TMR1H:TMR1L initial value */
    bool             enableInt;     /* Enable overflow interrupt  */
} Timer1_Config;

void Timer1_init        (const Timer1_Config *config);
void Timer1_deInit      (void);
void Timer1_setPreload  (uint16 value);
void Timer1_setCallBack (void (*ptr)(void));

#endif /* TIMER1_H */
