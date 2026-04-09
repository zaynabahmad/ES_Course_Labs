#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/* Timer Mode */
#define TIMER0_MODE_TIMER   0
#define TIMER0_MODE_COUNTER 1

#define TIMER0_MODE   TIMER0_MODE_TIMER

/* Prescaler */
#define TIMER0_PRESCALER  0   // 0 → assigned to Timer0

/* Prescaler Value (choose one) */
#define TIMER0_PRESCALER_VALUE  0b000   // 1:2

/* Preload Value */
#define TIMER0_PRELOAD_VALUE   0

#endif