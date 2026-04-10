#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit(void)
{

    SSPCON &= 0xF0;
    SSPCON |= SPI_MASTER_CLOCK_RATE;


    if(SPI_CLOCK_POLARITY) SET_BIT(SSPCON, CKP);
    else CLR_BIT(SSPCON, CKP);

    if(SPI_CLOCK_PHASE) SET_BIT(SSPSTAT, CKE);
    else CLR_BIT(SSPSTAT, CKE);


    if(SPI_SAMPLE_PHASE) SET_BIT(SSPSTAT, SMP);
    else CLR_BIT(SSPSTAT, SMP);


    CLR_BIT(TRISC, 5);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 3);

    SET_BIT(SSPCON, SSPEN);
}

void SPI_voidSlaveInit(void)
{

    SSPCON &= 0xF0;
    SSPCON |= 0x04;


    if(SPI_CLOCK_POLARITY) SET_BIT(SSPCON, CKP);
    else CLR_BIT(SSPCON, CKP);

    if(SPI_CLOCK_PHASE) SET_BIT(SSPSTAT, CKE);
    else CLR_BIT(SSPSTAT, CKE);


    CLR_BIT(SSPSTAT, SMP);

    CLR_BIT(TRISC, 5);
    SET_BIT(TRISC, 4);
    SET_BIT(TRISC, 3);


    ADCON1 = 0x06;
    SET_BIT(TRISA, 5);


    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
    SSPBUF = Copy_u8Data;

    while(!GET_BIT(SSPSTAT, BF));

    return SSPBUF;
}