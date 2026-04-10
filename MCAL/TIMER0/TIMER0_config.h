#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/* --- TIMER0 MODE SELECTION --- 
 * Options: 
 * 1. TIMER0_TIMER_MODE   (Internal Clock Fosc/4)
 * 2. TIMER0_COUNTER_MODE (External Clock on T0CKI pin)
 */
#define TIMER0_MODE  TIMER0_TIMER_MODE

/* --- PRESCALER ASSIGNMENT ---
 * Options:
 * 1. PRESCALER_ASSIGNED_TO_TIMER0
 * 2. PRESCALER_ASSIGNED_TO_WDT
 */
#define PRESCALER_ASSIGNMENT  PRESCALER_ASSIGNED_TO_TIMER0

/* --- PRESCALER VALUE ---
 * Options: 0 to 7 (Translates to 1:2 up to 1:256 for Timer0)
 * 0 = 1:2
 * 1 = 1:4
 * 2 = 1:8
 * 3 = 1:16
 * 4 = 1:32
 * 5 = 1:64
 * 6 = 1:128
 * 7 = 1:256
 */
#define TIMER0_PRESCALER_VALUE  7 

#endif