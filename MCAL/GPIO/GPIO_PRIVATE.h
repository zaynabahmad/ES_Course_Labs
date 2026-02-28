#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Register Definitions for PIC16F877A */

#define TRISA   (*((volatile unsigned char*)0x85))
#define TRISB   (*((volatile unsigned char*)0x86))
#define TRISC   (*((volatile unsigned char*)0x87))
#define TRISD   (*((volatile unsigned char*)0x88))
#define TRISE   (*((volatile unsigned char*)0x89))

#define PORTA   (*((volatile unsigned char*)0x05))
#define PORTB   (*((volatile unsigned char*)0x06))
#define PORTC   (*((volatile unsigned char*)0x07))
#define PORTD   (*((volatile unsigned char*)0x08))
#define PORTE   (*((volatile unsigned char*)0x09))

#endif