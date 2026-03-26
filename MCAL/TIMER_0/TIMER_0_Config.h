#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H

/* Options: TIMER0_TIMER_MODE, TIMER0_COUNTER_MODE */
#define TIMER0_MODE             TIMER0_TIMER_MODE

/* Options: 0 to 7 (corresponds to prescaler values 2 to 256) */
#define TIMER0_PRESCALER_VAL    TIMER0_PRESCALER_8

/* If Counter Mode, Options: 0 for rising edge, 1 for falling edge */
#define TIMER0_COUNTER_EDGE     0

#endif
