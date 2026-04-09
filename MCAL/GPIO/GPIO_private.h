#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

// PORTA Registers
#define DDRA   (*(volatile unsigned char*)0x3A)
#define PORTA  (*(volatile unsigned char*)0x3B)
#define PINA   (*(volatile unsigned char*)0x39)

// PORTB Registers
#define DDRB   (*(volatile unsigned char*)0x37)
#define PORTB  (*(volatile unsigned char*)0x38)
#define PINB   (*(volatile unsigned char*)0x36)

// PORTC Registers
#define DDRC   (*(volatile unsigned char*)0x34)
#define PORTC  (*(volatile unsigned char*)0x35)
#define PINC   (*(volatile unsigned char*)0x33)

// PORTD Registers
#define DDRD   (*(volatile unsigned char*)0x31)
#define PORTD  (*(volatile unsigned char*)0x32)
#define PIND   (*(volatile unsigned char*)0x30)

#endif