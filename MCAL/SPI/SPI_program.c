#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"

#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\SPI\SPI_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\SPI\SPI_interface.h"

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