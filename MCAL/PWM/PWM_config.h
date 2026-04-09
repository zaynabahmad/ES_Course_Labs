#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* F_CPU = 4 MHz
 *
 * PWM frequency = Fosc / (4 * T2_Prescaler * (PR2 + 1))
 *
 * T2CKPS1:T2CKPS0 → prescaler
 *   00 = 1:1
 *   01 = 1:4
 *   1x = 1:16
 *
 * Target: ~4 kHz PWM with prescaler 1:1, PR2 = 249
 *   f = 4 000 000 / (4 * 1 * 250) = 4 000 Hz
 *   Resolution = log2(4 * 1 * 250) = log2(1000) ≈ 10 bits
 */
#define PWM_PR2_VALUE       249     /* Timer2 period register value */
#define PWM_T2_PRESCALER    0x00    /* T2CKPS<1:0>: 00 = 1:1 */

#endif
