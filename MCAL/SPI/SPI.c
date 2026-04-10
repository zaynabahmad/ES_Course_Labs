#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

void SPI_MasterInit(void)
{
    /* Configure SPI pins for Master mode */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT); // SCK
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT); // SDO
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);  // SDI

    /* Enable SPI, Master mode, clock = FOSC/4 */
    SSPCON = 0x20;
    SSPSTAT = 0x00;
}

u8 SPI_Transfer(u8 Data)
{
    SSPBUF = Data;
    /* Wait until buffer full flag is set (Bit 0 of SSPSTAT) */
    while(!GET_BIT(SSPSTAT, 0));
    return SSPBUF;
}
