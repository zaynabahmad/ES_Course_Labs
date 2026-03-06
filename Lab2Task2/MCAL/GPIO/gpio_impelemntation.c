#include "gpio_interface.h"

volatile unsigned char* GPIO_GetTRISRegister(unsigned char port)
{
    switch(port)
    {
        case _PORTA: return &TRISA;
        case _PORTB: return &TRISB;
        case _PORTC: return &TRISC;
        case _PORTD: return &TRISD;
        case _PORTE: return &TRISE;
        default: return 0;
    }
}

volatile unsigned char* GPIO_GetPORTRegister(unsigned char port)
{
    switch(port)
    {
        case _PORTA: return &PORTA;
        case _PORTB: return &PORTB;
        case _PORTC: return &PORTC;
        case _PORTD: return &PORTD;
        case _PORTE: return &PORTE;
        default: return 0;
    }
}



void GPIO_Init(void)
{
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0xFF;
    TRISE = 0xFF;

    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;

    ADCON1 = 0x06;
}

void setpindirection(unsigned char port, unsigned char pin, bool direction)
{
    volatile unsigned char* TRIS_reg = GPIO_GetTRISRegister(port);
    if(TRIS_reg == 0) return;

    if(direction == OUTPUT)
        *TRIS_reg &= ~(1 << pin);
    else
        *TRIS_reg |= (1 << pin); 
}

void setpinvalue(unsigned char port, unsigned char pin, bool value)
{
    volatile unsigned char* PORT_reg = GPIO_GetPORTRegister(port);
    if(PORT_reg == 0) return;

    if(value == HIGH)
        *PORT_reg |= (1 << pin);
    else
        *PORT_reg &= ~(1 << pin);
}

unsigned char getpinvalue(unsigned char port, unsigned char pin)
{
    volatile unsigned char* PORT_reg = GPIO_GetPORTRegister(port);
    if(PORT_reg == 0) return 0;

    return ((*PORT_reg >> pin) & 0x01);
}