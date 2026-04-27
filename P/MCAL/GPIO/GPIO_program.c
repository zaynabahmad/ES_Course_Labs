/* ============================================================
 * GPIO_program.c  -  GPIO driver implementation
 * Target : PIC16F877A  |  Compiler : mikroC Pro for PIC
 * ============================================================ */

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "../../SERVICES/bit_math.h"

/* Helper macros - map port enum to TRIS/PORT register */
#define TRIS_REG(port)  (*tris_regs[port])
#define PORT_REG(port)  (*port_regs[port])

/* Register pointer arrays indexed by port enum (PORTA=0 .. PORTE=4) */
static volatile unsigned char * const tris_regs[] =
{
    (volatile unsigned char*)0x85,   /* TRISA */
    (volatile unsigned char*)0x86,   /* TRISB */
    (volatile unsigned char*)0x87,   /* TRISC */
    (volatile unsigned char*)0x88,   /* TRISD */
    (volatile unsigned char*)0x89    /* TRISE */
};

static volatile unsigned char * const port_regs[] =
{
    (volatile unsigned char*)0x05,   /* PORTA */
    (volatile unsigned char*)0x06,   /* PORTB */
    (volatile unsigned char*)0x07,   /* PORTC */
    (volatile unsigned char*)0x08,   /* PORTD */
    (volatile unsigned char*)0x09    /* PORTE */
};

/* ------------------------------------------------------------ */
void GPIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction)
{
    if (direction == INPUT)
        SET_BIT(TRIS_REG(port), pin);
    else
        CLR_BIT(TRIS_REG(port), pin);
}

/* ------------------------------------------------------------ */
void GPIO_WritePin(unsigned char port, unsigned char pin, unsigned char value)
{
    if (value == HIGH)
        SET_BIT(PORT_REG(port), pin);
    else
        CLR_BIT(PORT_REG(port), pin);
}

/* ------------------------------------------------------------ */
unsigned char GPIO_ReadPin(unsigned char port, unsigned char pin)
{
    return GET_BIT(PORT_REG(port), pin);
}

/* ------------------------------------------------------------ */
void GPIO_TogglePin(unsigned char port, unsigned char pin)
{
    TOG_BIT(PORT_REG(port), pin);
}
