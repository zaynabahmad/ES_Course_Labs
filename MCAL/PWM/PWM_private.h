#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define TCCR0   (*(volatile unsigned char*)0x53)
#define OCR0    (*(volatile unsigned char*)0x5C)
#define DDRB    (*(volatile unsigned char*)0x37)

#endif