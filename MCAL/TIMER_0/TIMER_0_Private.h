#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#define TMR0       (*(volatile u8*)0x01)
#define OPTION_REG (*(volatile u8*)0x81)
#define INTCON     (*(volatile u8*)0x0B)

#define T0CS 5
#define PSA  3
#define T0IF 2
#define T0IE 5
#define GIE  7

#endif
