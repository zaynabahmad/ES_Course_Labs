#ifndef TIMER_0_CONFIG_H
#define TIMER_0_CONFIG_H

/* F_CPU = 4 MHz */

/* PS2:PS0 encoding written to OPTION_REG bits 2:0 */
/* 000=1:2, 001=1:4, 010=1:8, 011=1:16, 100=1:32, 101=1:64, 110=1:128, 111=1:256 */
#define TIMER0_PS_BITS      0x07    /* 111 = prescaler 1:256 */

/* Default preload value loaded into TMR0 before each start */
/* Overflow period = 4 * Prescaler * (256 - PRELOAD) / Fosc             */
/* With PS=256, PRELOAD=0:  65.536 ms @ 4 MHz                           */
#define TIMER0_DEFAULT_PRELOAD  0x00

#endif
