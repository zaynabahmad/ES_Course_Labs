#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H

/*
 * Prescaler:
 * 0 ? 1:2
 * 1 ? 1:4
 * 2 ? 1:8
 * 3 ? 1:16
 * 4 ? 1:32
 * 5 ? 1:64
 * 6 ? 1:128
 * 7 ? 1:256
 */
#define TIMER0_PRESCALER   7   // 1:256

/* Initial preload value */
#define TIMER0_PRELOAD     0

#endif