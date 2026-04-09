#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define TRISA    (*(volatile uint8*)0x85)
#define PORTA    (*(volatile uint8*)0x05)
#define TRISB    (*(volatile uint8*)0x86)
#define PORTB    (*(volatile uint8*)0x06)
#define TRISC    (*(volatile uint8*)0x87)
#define PORTC    (*(volatile uint8*)0x07)
#define TRISD    (*(volatile uint8*)0x88)
#define PORTD    (*(volatile uint8*)0x08)
#define TRISE    (*(volatile uint8*)0x89)
#define PORTE    (*(volatile uint8*)0x09)

#endif