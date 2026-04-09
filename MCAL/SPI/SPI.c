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


    CLR_BIT(TRISC, 5); // SDO -> Output
    SET_BIT(TRISC, 4); // SDI -> Input
    CLR_BIT(TRISC, 3); // SCK -> Output

    /*Enable Synchronous Serial Port [cite: 782] */
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


    CLR_BIT(TRISC, 5); // SDO -> Output
    SET_BIT(TRISC, 4); // SDI -> Input
    SET_BIT(TRISC, 3); // SCK -> Input


    ADCON1 = 0x06;     // All analog pins to digital
    SET_BIT(TRISA, 5); // SS -> Input


    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
    /* Transfer data to buffer [cite: 806] */
    SSPBUF = Copy_u8Data;

    /* Wait until transmission is complete [cite: 806] */
    while(!GET_BIT(SSPSTAT, BF));

    /* Return received data */
    return SSPBUF;
}