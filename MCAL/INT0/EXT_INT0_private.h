#ifndef EXT_INT0_PRIVATE_H
#define EXT_INT0_PRIVATE_H

// ================= Registers Addresses =================

// PORTB register (RB0 is bit 0)
#define PORTB_REG   (*((volatile unsigned char*)0x06))

// TRISB register
#define TRISB_REG   (*((volatile unsigned char*)0x86))

// INTCON register
#define INTCON_REG  (*((volatile unsigned char*)0x0B))

// OPTION_REG register
#define OPTION_REG_REG  (*((volatile unsigned char*)0x81))


// ================= Bit Positions =================

// RB0 (INT0 pin)
#define INT0_PIN_BIT   0
#define INT0_DIR_BIT   0

// INTCON bits
#define GIE_BIT   7
#define INTE_BIT  4
#define INTF_BIT  1

// OPTION_REG bits
#define INTEDG_BIT 6


#endif