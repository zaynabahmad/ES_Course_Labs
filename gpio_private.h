#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "../../SERVICES/types.h"

/* Port direction registers */
#define TRIS_A   (*((volatile u8*)0x85))
#define TRIS_B   (*((volatile u8*)0x86))
#define TRIS_C   (*((volatile u8*)0x87))
#define TRIS_D   (*((volatile u8*)0x88))
#define TRIS_E   (*((volatile u8*)0x89))

/* Port data registers */
#define PORT_A   (*((volatile u8*)0x05))
#define PORT_B   (*((volatile u8*)0x06))
#define PORT_C   (*((volatile u8*)0x07))
#define PORT_D   (*((volatile u8*)0x08))
#define PORT_E   (*((volatile u8*)0x09))

#endif