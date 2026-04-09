#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_private.h"
#include "SPI_interface.h"

#include "../GPIO/GPIO_interface.h"

void SPI_Init(void)
{
    //  Configure SPI Pins
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT); // SCK
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);  // SDI
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT); // SDO

    //  SPI Mode (Mode 0)
    CLR_BIT(SSPCON_REG, 4);  // CKP = 0
    SET_BIT(SSPSTAT_REG, 6); // CKE = 1
    SET_BIT(SSPSTAT_REG, 7); // SMP = 1

    // Enable SPI Master
    SSPCON_REG = 0x20; // Master, Fosc/4
}

u8 SPI_Transmit(u8 _data)
{
    SSPBUF_REG = _data;

    while(!GET_BIT(SSPSTAT_REG, BF_BIT));

    return SSPBUF_REG;
}