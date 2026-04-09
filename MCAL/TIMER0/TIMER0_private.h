#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TCCR0   (*(volatile unsigned char*)0x53)
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TIMSK   (*(volatile unsigned char*)0x59)
#define TIFR    (*(volatile unsigned char*)0x58)

#endif