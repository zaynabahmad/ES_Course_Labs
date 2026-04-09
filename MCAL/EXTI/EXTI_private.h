#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define INTCON_REG   *((volatile unsigned char*)0x0B)
#define OPTION_REG   *((volatile unsigned char*)0x81)

// INTCON bits
#define GIE 7
#define INTE 4
#define INTF 1

// OPTION_REG bits
#define INTEDG 6

#endif