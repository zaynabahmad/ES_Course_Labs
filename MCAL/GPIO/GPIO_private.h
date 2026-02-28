#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Register Definitions for PIC16F877A */

#define TRISA   (*((volatile u8*)0x85))
#define TRISB   (*((volatile u8*)0x86))
#define TRISC   (*((volatile u8*)0x87))
#define TRISD   (*((volatile u8*)0x88))
#define TRISE   (*((volatile u8*)0x89))

#define PORTA   (*((volatile u8*)0x05))
#define PORTB   (*((volatile u8*)0x06))
#define PORTC   (*((volatile u8*)0x07))
#define PORTD   (*((volatile u8*)0x08))
#define PORTE   (*((volatile u8*)0x09))

#define INTCON  (*((volatile u8*)0x8B))
#define OPTION_REG  (*((volatile u8*)0x181))

#define RISING_EDGE  1
#define FALLING_EDGE 0


#endif