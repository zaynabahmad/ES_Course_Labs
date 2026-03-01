#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Definitions for PIC16F877A - Renamed to bypass mikroC built-in SFR conflicts */

#define GPIO_TRISA_REG   (*((volatile u8*)0x85))
#define GPIO_TRISB_REG   (*((volatile u8*)0x86))
#define GPIO_TRISC_REG   (*((volatile u8*)0x87))
#define GPIO_TRISD_REG   (*((volatile u8*)0x88))
#define GPIO_TRISE_REG   (*((volatile u8*)0x89))

#define GPIO_PORTA_REG   (*((volatile u8*)0x05))
#define GPIO_PORTB_REG   (*((volatile u8*)0x06))
#define GPIO_PORTC_REG   (*((volatile u8*)0x07))
#define GPIO_PORTD_REG   (*((volatile u8*)0x08))
#define GPIO_PORTE_REG   (*((volatile u8*)0x09))

#endif
