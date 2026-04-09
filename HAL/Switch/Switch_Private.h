#ifndef SWITCH_PRIVATE_H
#define SWITCH_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


#define TRISA_REG    (*(volatile u8*)0x85)
#define TRISB_REG    (*(volatile u8*)0x86)
#define TRISC_REG    (*(volatile u8*)0x87)
#define TRISD_REG    (*(volatile u8*)0x88)


#define PORTA_REG    (*(volatile u8*)0x05)
#define PORTB_REG    (*(volatile u8*)0x06)
#define PORTC_REG    (*(volatile u8*)0x07)
#define PORTD_REG    (*(volatile u8*)0x08)


#define SW_PORTA     0
#define SW_PORTB     1
#define SW_PORTC     2
#define SW_PORTD     3

#endif /* SWITCH_PRIVATE_H */