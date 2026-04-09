#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/*  Clock Source: TIMER0_INTERNAL_CLK or TIMER0_EXTERNAL_CLK */
#define TIMER0_CLK_SRC      TIMER0_INTERNAL_CLK

/*  Prescaler: TIMER0_PRESCALER_OFF, TIMER0_PRESCALER_2 .. TIMER0_PRESCALER_256 */
#define TIMER0_PRESCALER     TIMER0_PRESCALER_8

/*  Preload value (0-255) for desired overflow period */
#define TIMER0_PRELOAD       0

#endif
