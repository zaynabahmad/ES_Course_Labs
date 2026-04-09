#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H

/*
    Configure Timer0 Prescaler Selection
    Options:
    0b000 - 1:2
    0b001 - 1:4
    0b010 - 1:8
    0b011 - 1:16
    0b100 - 1:32
    0b101 - 1:64
    0b110 - 1:128
    0b111 - 1:256
*/
#define TIMER0_PRESCALER_VAL    0b111

/* Configure Initial Preload Value */
#define TIMER0_INIT_VAL         0x00

/* Enable Prescaler (0 for Timer0, 1 for WDT) */
#define TIMER0_PSA_ASSINGMENT   0

/* Timer0 Clock Source (0 for Internal Fosc/4, 1 for External T0CKI) */
#define TIMER0_CLOCK_SOURCE     0

#endif
