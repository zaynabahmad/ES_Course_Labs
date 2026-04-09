 #ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Port Register Addresses*/
#define PORTA_REG    (*((volatile unsigned char*)0x05))
#define PORTB_REG    (*((volatile unsigned char*)0x06))
#define PORTC_REG    (*((volatile unsigned char*)0x07))
#define PORTD_REG    (*((volatile unsigned char*)0x08))
#define PORTE_REG    (*((volatile unsigned char*)0x09))

/* Direction Register Addresses*/
#define TRISA_REG    (*((volatile unsigned char*)0x85))
#define TRISB_REG    (*((volatile unsigned char*)0x86))
#define TRISC_REG   (*((volatile unsigned char*)0x87))
#define TRISD_REG    (*((volatile unsigned char*)0x88))
#define TRISE_REG    (*((volatile unsigned char*)0x89))

#endif