/*
 * gpio.c
 * MCAL - GPIO Driver Implementation for PIC16F877A
 */

#include "gpio.h"
#include "gpio_private.h"

/* =====================================================
 * Internal Helper: Get PORT register pointer
 * ===================================================== */
static volatile unsigned char* GPIO_GetPortReg(GPIO_Port_t port)
{
    switch(port)
    {
        case GPIO_PORTA: return &PORTA_REG;
        case GPIO_PORTB: return &PORTB_REG;
        case GPIO_PORTC: return &PORTC_REG;
        case GPIO_PORTD: return &PORTD_REG;
        case GPIO_PORTE: return &PORTE_REG;
        default:         return &PORTA_REG;
    }
}

/* Internal Helper: Get TRIS register pointer */
static volatile unsigned char* GPIO_GetTrisReg(GPIO_Port_t port)
{
    switch(port)
    {
        case GPIO_PORTA: return &TRISA_REG;
        case GPIO_PORTB: return &TRISB_REG;
        case GPIO_PORTC: return &TRISC_REG;
        case GPIO_PORTD: return &TRISD_REG;
        case GPIO_PORTE: return &TRISE_REG;
        default:         return &TRISA_REG;
    }
}

/* =====================================================
 * Function Implementations
 * ===================================================== */

void GPIO_SetPinDirection(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_Dir_t dir)
{
    volatile unsigned char* trisReg = GPIO_GetTrisReg(port);
    if(dir == GPIO_INPUT)
    {
        *trisReg |= (1 << pin);    /* Set bit  = input  */
    }
    else
    {
        *trisReg &= ~(1 << pin);   /* Clear bit = output */
    }
}

void GPIO_SetPortDirection(GPIO_Port_t port, u8 dir)
{
    volatile unsigned char* trisReg = GPIO_GetTrisReg(port);
    *trisReg = dir;
}

void GPIO_WritePin(GPIO_Port_t port, GPIO_Pin_t pin, GPIO_Level_t level)
{
    volatile unsigned char* portReg = GPIO_GetPortReg(port);
    if(level == GPIO_HIGH)
    {
        *portReg |= (1 << pin);
    }
    else
    {
        *portReg &= ~(1 << pin);
    }
}

void GPIO_WritePort(GPIO_Port_t port, u8 value)
{
    volatile unsigned char* portReg = GPIO_GetPortReg(port);
    *portReg = value;
}

GPIO_Level_t GPIO_ReadPin(GPIO_Port_t port, GPIO_Pin_t pin)
{
    volatile unsigned char* portReg = GPIO_GetPortReg(port);
    return ((*portReg >> pin) & 0x01) ? GPIO_HIGH : GPIO_LOW;
}

u8 GPIO_ReadPort(GPIO_Port_t port)
{
    volatile unsigned char* portReg = GPIO_GetPortReg(port);
    return *portReg;
}

void GPIO_TogglePin(GPIO_Port_t port, GPIO_Pin_t pin)
{
    volatile unsigned char* portReg = GPIO_GetPortReg(port);
    *portReg ^= (1 << pin);
}
