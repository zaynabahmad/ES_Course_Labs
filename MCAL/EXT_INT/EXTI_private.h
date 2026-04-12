#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define INTCON_REG     *((volatile unsigned char *)0x0B)
#define OPTION_REG     *((volatile unsigned char *)0x81)

/* INTCON bits */
#define GIE_BIT        7
#define INTE_BIT       4
#define INTF_BIT       1

/* OPTION_REG bits */
#define INTEDG_BIT     6

#endif
