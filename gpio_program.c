#include "gpio_interface.h"
#include "gpio_private.h"
#include "gpio_config.h"
#include "../../SERVICES/bit_ops.h"

/* Array of pointers to TRIS and PORT registers */
static volatile unsigned char * const tris_regs[5] = {&TRIS_A, &TRIS_B, &TRIS_C, &TRIS_D, &TRIS_E};
static volatile unsigned char * const port_regs[5] = {&PORT_A, &PORT_B, &PORT_C, &PORT_D, &PORT_E};

void GPIO_ConfigPin(u8 port, u8 pin, u8 direction)
{
    if(port > PORTE_ID) return;
    if(direction == DIR_OUT)
        BIT_CLEAR(*tris_regs[port], pin);
    else
        BIT_SET(*tris_regs[port], pin);
}

void GPIO_WritePin(u8 port, u8 pin, u8 value)
{
    if(port > PORTE_ID) return;
    if(value == LEVEL_HIGH)
        BIT_SET(*port_regs[port], pin);
    else
        BIT_CLEAR(*port_regs[port], pin);
}

u8 GPIO_ReadPin(u8 port, u8 pin)
{
    if(port > PORTE_ID) return 0;
    return BIT_READ(*port_regs[port], pin);
}

void GPIO_InitAll(void)
{
    TRIS_A = PORTA_DIR_DEFAULT;
    TRIS_B = PORTB_DIR_DEFAULT;
    TRIS_C = PORTC_DIR_DEFAULT;
    TRIS_D = PORTD_DIR_DEFAULT;
    TRIS_E = PORTE_DIR_DEFAULT;

    PORT_A = PORTA_LATCH_DEFAULT;
    PORT_B = PORTB_LATCH_DEFAULT;
    PORT_C = PORTC_LATCH_DEFAULT;
    PORT_D = PORTD_LATCH_DEFAULT;
    PORT_E = PORTE_LATCH_DEFAULT;
}