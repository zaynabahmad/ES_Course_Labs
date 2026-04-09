/*
 * pic_config.h
 * Configuration bits and clock definition for PIC16F877A
 * Include this ONLY in the main application file (once per project)
 */

#ifndef PIC_CONFIG_H
#define PIC_CONFIG_H

#include <xc.h>

/* ---- Configuration Bits ---- */
// CONFIG
#pragma config FOSC  = HS       // High-Speed crystal oscillator
#pragma config WDTE  = OFF      // Watchdog Timer disabled
#pragma config PWRTE = ON       // Power-up Timer enabled
#pragma config BOREN = ON       // Brown-out Reset enabled
#pragma config LVP   = OFF      // Low-Voltage Programming disabled
#pragma config CPD   = OFF      // Data EEPROM code protection off
#pragma config WRT   = OFF      // Flash write protection off
#pragma config CP    = OFF      // Code protection off

/* ---- Clock Frequency ---- */
#define F_CPU   8000000UL       /* 8 MHz crystal — match Proteus crystal value */
#define _XTAL_FREQ F_CPU        /* Required by __delay_ms() / __delay_us() */

#endif /* PIC_CONFIG_H */
