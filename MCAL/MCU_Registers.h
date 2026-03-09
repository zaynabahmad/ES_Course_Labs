#ifndef MCU_REGISTERS_H
#define MCU_REGISTERS_H



#define TRISA   (*((volatile u8*)0x85))
#define TRISB   (*((volatile u8*)0x86))
#define TRISC   (*((volatile u8*)0x87))
#define TRISD   (*((volatile u8*)0x88))
#define TRISE   (*((volatile u8*)0x89))

#define PORTA   (*((volatile u8*)0x05))
#define PORTB   (*((volatile u8*)0x06))
#define PORTC   (*((volatile u8*)0x07))
#define PORTD   (*((volatile u8*)0x08))
#define PORTE   (*((volatile u8*)0x09))

#define INTCON (*((volatile u8*)0x0B))
#define TMR0 (*((volatile u8*)0x01))

#define GIE 7
#define PEIE 6
#define TMR0IE 5
#define INTE 4
#define TMR0IF 2
#define INTF 1


#define OPTION_REG (*((volatile u8*)0x81))

#define INTEDG 6
#define T0CS 5
#define T0SE 4
#define PSA 3
#define PS2 2
#define PS1 1
#define PS0 0

#define ADCON1_REG  (*(volatile unsigned char *)0x9F)




#define RISING_EDGE 1
#define FALLING_EDGE 0


#endif