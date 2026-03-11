#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Register Definitions for PIC16F877A */

#define TRISA   (*((volatile uint8*)0x85))
#define TRISB   (*((volatile uint8*)0x86))
#define TRISC   (*((volatile uint8*)0x87))
#define TRISD   (*((volatile uint8*)0x88))
#define TRISE   (*((volatile uint8*)0x89))

#define PORTA   (*((volatile uint8*)0x05))
#define PORTB   (*((volatile uint8*)0x06))
#define PORTC   (*((volatile uint8*)0x07))
#define PORTD   (*((volatile uint8*)0x08))
#define PORTE   (*((volatile uint8*)0x09))

#endif