#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

/* Timer0 Prescaler Bit Configurations */
#define TIMER0_PRESCALER_2    0b000
#define TIMER0_PRESCALER_4    0b001
#define TIMER0_PRESCALER_8    0b010
#define TIMER0_PRESCALER_16   0b011
#define TIMER0_PRESCALER_32   0b100
#define TIMER0_PRESCALER_64   0b101
#define TIMER0_PRESCALER_128  0b110
#define TIMER0_PRESCALER_256  0b111

/* Timer0 Clock Source Options */
#define TIMER0_INTERNAL_CLK   0
#define TIMER0_EXTERNAL_CLK   1

/* Register Bits */
#define T0CS    5   /* OPTION_REG: Timer0 Clock Source Select bit */
#define PSA     3   /* OPTION_REG: Prescaler Assignment bit */
#define GIE     7   /* INTCON: Global Interrupt Enable bit */

#endif