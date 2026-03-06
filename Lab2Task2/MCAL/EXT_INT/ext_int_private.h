#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

/* Registers */

#define INTCON      (*((volatile unsigned char*)0x0B))
#define OPTION_REG  (*((volatile unsigned char*)0x81))

/* INTCON bits */

#define GIE_BIT  7
#define INTE_BIT 4
#define INTF_BIT 1

/* OPTION_REG bit */

#define INTEDGE_BIT 6


/* Edge types */

#define RISING_EDGE  1
#define FALLING_EDGE 0

#endif