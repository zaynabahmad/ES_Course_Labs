#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

// MCU Control Register
#define MCUCR   (*(volatile unsigned char*)0x55)

// General Interrupt Control Register
#define GICR    (*(volatile unsigned char*)0x5B)

// General Interrupt Flag Register
#define GIFR    (*(volatile unsigned char*)0x5A)

// Global Interrupt Enable
#define SREG    (*(volatile unsigned char*)0x5F)

#endif