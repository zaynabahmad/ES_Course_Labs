#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

#define INTCON_REG         (*((volatile u8*)0x0B))
#define OPTION_REG         (*((volatile u8*)0x81))

/* Bit Positions */
#define GIE_BIT            7
#define INTE_BIT           4
#define INTF_BIT           1
#define INTEDG_BIT         6

#endif