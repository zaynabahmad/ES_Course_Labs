#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Memory mapping for Port Data Registers */
#define PORTA_REG    (*((volatile u8*)0x05))
#define PORTB_REG    (*((volatile u8*)0x06))
#define PORTC_REG    (*((volatile u8*)0x07))
#define PORTD_REG    (*((volatile u8*)0x08))
#define PORTE_REG    (*((volatile u8*)0x09))

/* Memory mapping for Direction Registers */
#define TRISA_REG    (*((volatile u8*)0x85))
#define TRISB_REG    (*((volatile u8*)0x86))
#define TRISC_REG    (*((volatile u8*)0x87))
#define TRISD_REG    (*((volatile u8*)0x88))
#define TRISE_REG    (*((volatile u8*)0x89))

#endif