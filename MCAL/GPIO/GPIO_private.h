#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define PORTA (*(volatile unsigned char*)0x05)
#define PORTB (*(volatile unsigned char*)0x06)

#define TRISA (*(volatile unsigned char*)0x85)
#define TRISB (*(volatile unsigned char*)0x86)

#endif