#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/* Timer0 Clock Source:
   0 -> Internal Instruction Cycle Clock (Fosc/4)
   1 -> Transition on T0CKI pin */
#define TIMER0_CLOCK_SOURCE   0

/* Prescaler Assignment:
   0 -> Timer0
   1 -> WDT */
#define TIMER0_PRESCALER_ASSIGN   0

/* Prescaler Rate (if assigned to Timer0):
   000 -> 1:2
   ...
   111 -> 1:256 (Rate 7) */
#define TIMER0_PRESCALER_RATE  7

#endif