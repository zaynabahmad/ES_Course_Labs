#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

#include "TIMER0_interface.h"

/*  8 MHz crystal  →  Fosc/4 = 2 MHz instruction clock
    Prescaler 1:256  →  Ttick = 0.5 µs × 256 = 128 µs

    Target: 1-second callback period
      Total counts  = 1 000 000 µs / 128 µs = 7812
      Full overflows = 7812 / 256 = 30  (7680 counts)
      Remaining      = 7812 − 7680 = 132 counts
      Preload        = 256 − 132  = 124

    Strategy: 30 full overflows (TMR0 reloaded to 0) then
              1 partial overflow (TMR0 reloaded to 124).
              Total = 30 × 256 + 132 = 7812 counts × 128 µs ≈ 1.000 s */

#define TIMER0_PRESCALER       TIMER0_PRESCALER_256
#define TIMER0_PRELOAD         124u   /* reload value for the final partial overflow */
#define TIMER0_OVF_FULL_COUNT  30u    /* number of full overflows before partial     */

#endif
