#ifndef TIMER0_CFG_H
#define TIMER0_CFG_H

/* Prescaler options */
#define TIMER0_PRESCALER_2      0
#define TIMER0_PRESCALER_4      1
#define TIMER0_PRESCALER_8      2
#define TIMER0_PRESCALER_16     3
#define TIMER0_PRESCALER_32     4
#define TIMER0_PRESCALER_64     5
#define TIMER0_PRESCALER_128    6
#define TIMER0_PRESCALER_256    7

/* Timer0 configuration for 1 second at 8MHz */
#define TIMER0_PRESCALER        TIMER0_PRESCALER_256
#define TIMER0_PRELOAD          124
#define TIMER0_OVERFLOWS        30

#endif