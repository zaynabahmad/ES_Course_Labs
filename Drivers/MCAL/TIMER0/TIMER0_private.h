#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

#define TMR0     (*(volatile uint8*)0x01)
#define OPTION_REG (*(volatile uint8*)0x81)
#define INTCON   (*(volatile uint8*)0x0B)

#endif