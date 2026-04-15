#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/SPI/SPI_private.h"
#include "../MCAL/SPI/SPI_config.h"

void SPI_voidInitMaster(void)
{

    SET_BIT(SPCR,SPE);
    SET_BIT(SPCR,MSTR);

    // Clock = Fosc/16
    CLR_BIT(SPCR,0);
    SET_BIT(SPCR,1);
}

void SPI_voidInitSlave(void)
{
    //Enable SPI
    SET_BIT(SPCR,SPE);

    //Slave
    CLR_BIT(SPCR,MSTR);
}

u8 SPI_u8SendReceive(u8 data)
{
    //Send data
    SPDR=data;

    //Wait for transmission
    while(GET_BIT(SPSR,SPIF)==0);

    // Return received data
    return SPDR;
}