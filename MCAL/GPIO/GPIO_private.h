#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* --- Data Direction Registers (TRISx) --- */
#define TRISA   (*(volatile unsigned char*)0x85)
#define TRISB   (*(volatile unsigned char*)0x86)
#define TRISC   (*(volatile unsigned char*)0x87)
#define TRISD   (*(volatile unsigned char*)0x88)
#define TRISE   (*(volatile unsigned char*)0x89)

/* --- Port Data Registers (PORTx) --- */
#define PORTA   (*(volatile unsigned char*)0x05)
#define PORTB   (*(volatile unsigned char*)0x06)
#define PORTC   (*(volatile unsigned char*)0x07)
#define PORTD   (*(volatile unsigned char*)0x08)
#define PORTE   (*(volatile unsigned char*)0x09)

/* --- Direction constants --- */
#define INPUT   1u
#define OUTPUT  0u

/* --- Logic level constants --- */
#define HIGH    1u
#define LOW     0u

/* --- Maximum valid pin number (ports are 8-bit) --- */
#define GPIO_MAX_PIN    7u

#endif /* GPIO_PRIVATE_H */