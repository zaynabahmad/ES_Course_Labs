#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Register Definitions for PIC16F877A */

#define TRISA   (*(u8*)0x85)
#define TRISB   (*(u8*)0x86)
#define TRISC   (*(u8*)0x87)
#define TRISD   (*(u8*)0x88)
#define TRISE   (*(u8*)0x89)

#define PORTA   (*(u8*)0x05)
#define PORTB   (*(u8*)0x06)
#define PORTC   (*(u8*)0x07)
#define PORTD   (*(u8*)0x08)
#define PORTE   (*(u8*)0x09)

#endif