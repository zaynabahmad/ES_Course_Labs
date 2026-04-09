/*
 * gpio_private.h
 * MCAL - GPIO Register Definitions for PIC16F877A
 * Private file - NOT to be included by APP layer
 */

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* =====================================================
 * PIC16F877A GPIO Port SFR Base Addresses
 * All addresses as per PIC16F877A datasheet
 * ===================================================== */

/* PORT Data Registers */
#define PORTA_REG    (*((volatile unsigned char*)0x05))
#define PORTB_REG    (*((volatile unsigned char*)0x06))
#define PORTC_REG    (*((volatile unsigned char*)0x07))
#define PORTD_REG    (*((volatile unsigned char*)0x08))
#define PORTE_REG    (*((volatile unsigned char*)0x09))

/* TRIS Direction Registers (Bank 1) */
#define TRISA_REG    (*((volatile unsigned char*)0x85))
#define TRISB_REG    (*((volatile unsigned char*)0x86))
#define TRISC_REG    (*((volatile unsigned char*)0x87))
#define TRISD_REG    (*((volatile unsigned char*)0x88))
#define TRISE_REG    (*((volatile unsigned char*)0x89))

/* Direction Macros */
#define GPIO_DIR_OUTPUT   0
#define GPIO_DIR_INPUT    1

#endif /* GPIO_PRIVATE_H */
