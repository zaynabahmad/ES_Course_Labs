#ifndef EXTI0_PRIVATE_H
#define EXTI0_PRIVATE_H

#define INTCON        *((volatile uint8*)0x0B)
#define OPTION_REG    *((volatile uint8*)0x81)
#define TRISB         *((volatile uint8*)0x86)

/* Bit Definitions */
#define GIE           7
#define INTE          4
#define INTF          1
#define INTEDG        6

#endif