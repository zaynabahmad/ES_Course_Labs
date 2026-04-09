#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_voidInit(void)
{
    // Enable SPI Master mode
    SET_BIT(SSPCON,5); // SSPEN
    SET_BIT(SSPCON,4); // CKP
}

unsigned char SPI_u8Transfer(unsigned char data)
{
    SSPBUF = data;

    while(!GET_BIT(SSPSTAT,0)); // BF flag

    return SSPBUF;
}