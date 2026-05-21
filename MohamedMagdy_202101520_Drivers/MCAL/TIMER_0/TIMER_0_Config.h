#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H

/* prescaler 1:256, preload gives ~10ms overflow @ 8MHz */
#define TIMER0_PRESCALER    TIMER0_PS_1_256
#define TIMER0_PRELOAD      178
#define TIMER0_CLK_INTERNAL 0

#endif
