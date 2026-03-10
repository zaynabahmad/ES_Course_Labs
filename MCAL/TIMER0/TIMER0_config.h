#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/*
 * Timer0 Configuration for ~10ms interrupt @ 8MHz oscillator
 * Fosc/4 = 2MHz => 0.5us per tick
 * Prescaler 1:256 => 128us per tick
 * 78 ticks => ~10ms (78 * 128us = 9.984ms)
 * TMR0 preload = 256 - 78 = 178
 */
#define TIMER0_PRESCALER_VALUE   0x07   /* PS2:PS0 = 111 => 1:256 prescaler */
#define TIMER0_PRELOAD           178

#endif
