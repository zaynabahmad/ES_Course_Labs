#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_interface.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\GPIO\GPIO_private.h"

static volatile unsigned char* GPIO_prvGetTRIS(unsigned char port)
{
    switch (port)
    {
        case 'A': return &TRISA;
        case 'B': return &TRISB;
        case 'C': return &TRISC;
        case 'D': return &TRISD;
        case 'E': return &TRISE;
        default:  return 0;
    }
}


static volatile unsigned char* GPIO_prvGetPORT(unsigned char port)
{
    switch (port)
    {
        case 'A': return &PORTA;
        case 'B': return &PORTB;
        case 'C': return &PORTC;
        case 'D': return &PORTD;
        case 'E': return &PORTE;
        default:  return 0;
    }
}

/* ---------------------------------------------------------- */
unsigned char GPIO_voidSetPinDirection(unsigned char port,
                                       unsigned char pin,
                                       unsigned char dir)
{
    volatile unsigned char *tris;


    if (pin > GPIO_MAX_PIN) { return GPIO_ERR_INVALID; }

    tris = GPIO_prvGetTRIS(port);
    if (tris == 0)           { return GPIO_ERR_INVALID; }

    if (dir == INPUT)
        SET_BIT(*tris, pin);
    else
        CLR_BIT(*tris, pin);

    return GPIO_OK;
}

/* ---------------------------------------------------------- */
unsigned char GPIO_voidSetPinValue(unsigned char port,
                                   unsigned char pin,
                                   unsigned char val)
{
    volatile unsigned char *preg;

    if (pin > GPIO_MAX_PIN) { return GPIO_ERR_INVALID; }

    preg = GPIO_prvGetPORT(port);
    if (preg == 0)          { return GPIO_ERR_INVALID; }

    if (val == HIGH)
        SET_BIT(*preg, pin);
    else
        CLR_BIT(*preg, pin);

    return GPIO_OK;
}

/* ---------------------------------------------------------- */
unsigned char GPIO_u8GetPinValue(unsigned char port,
                                 unsigned char pin)
{
    volatile unsigned char *preg;

    if (pin > GPIO_MAX_PIN) { return GPIO_ERR_INVALID; }

    preg = GPIO_prvGetPORT(port);
    if (preg == 0)          { return GPIO_ERR_INVALID; }

    return GET_BIT(*preg, pin);
}

/* ---------------------------------------------------------- */
unsigned char GPIO_voidTogglePin(unsigned char port,
                                 unsigned char pin)
{
    volatile unsigned char *preg;

    if (pin > GPIO_MAX_PIN) { return GPIO_ERR_INVALID; }

    preg = GPIO_prvGetPORT(port);
    if (preg == 0)          { return GPIO_ERR_INVALID; }


    TOG_BIT(*preg, pin);

    return GPIO_OK;
}

/* ---------------------------------------------------------- */
unsigned char GPIO_voidSetPortDirection(unsigned char port,
                                        unsigned char dir_mask)
{
    volatile unsigned char *tris = GPIO_prvGetTRIS(port);
    if (tris == 0) { return GPIO_ERR_INVALID; }

    *tris = dir_mask;
    return GPIO_OK;
}

/* ---------------------------------------------------------- */
unsigned char GPIO_voidSetPortValue(unsigned char port,
                                    unsigned char value)
{
    volatile unsigned char *preg = GPIO_prvGetPORT(port);
    if (preg == 0) { return GPIO_ERR_INVALID; }

    *preg = value;
    return GPIO_OK;
}