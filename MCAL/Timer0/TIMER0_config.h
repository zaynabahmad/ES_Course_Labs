#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

#define TIMER0_CLK_SOURCE       TIMER0_INTERNAL_CLK
#define TIMER0_PRESCALER        TIMER0_PRESCALER_256
#define TIMER0_PRELOAD_VALUE    61  /* ~50ms per overflow at 4MHz */

#endif