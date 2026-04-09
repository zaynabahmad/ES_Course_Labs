#include "SPI_Interface.h"

void SPI_Init(void)
{
    #if (SPI_MODE == SPI_MASTER_FOSC_4) || (SPI_MODE == SPI_MASTER_FOSC_16) || (SPI_MODE == SPI_MASTER_FOSC_64)
        CLR_BIT(TRISC, SCK_PIN);    
        CLR_BIT(TRISC, SDO_PIN);    
        SET_BIT(TRISC, SDI_PIN);    
    #else
        SET_BIT(TRISC, SCK_PIN);   
        CLR_BIT(TRISC, SDO_PIN);   
        SET_BIT(TRISC, SDI_PIN);    
    #endif

    /* Clear SSPCON and set mode */
    SSPCON = 0x00;
    SSPCON |= (SPI_MODE & 0x0F);

    /* Clock Polarity */
    #if SPI_CKP == 1
        SET_BIT(SSPCON, CKP_BIT);
    #else
        CLR_BIT(SSPCON, CKP_BIT);
    #endif

    /* Clock Edge */
    #if SPI_CKE == 1
        SET_BIT(SSPSTAT, CKE_BIT);
    #else
        CLR_BIT(SSPSTAT, CKE_BIT);
    #endif

    /* Sample Bit */
    #if SPI_SMP == 1
        SET_BIT(SSPSTAT, SMP_BIT);
    #else
        CLR_BIT(SSPSTAT, SMP_BIT);
    #endif

    /* Enable MSSP module */
    SET_BIT(SSPCON, SSPEN_BIT);

    CLR_BIT(SSPCON, WCOL_BIT);
    CLR_BIT(SSPCON, SSPOV_BIT);
}

u8 SPI_Transfer(u8 Data)
{
    u8 dummy;

    CLR_BIT(SSPCON, WCOL_BIT);

    SSPBUF = Data;

    while(!GET_BIT(SSPSTAT, BF_BIT));

    dummy = SSPBUF;
    return dummy;
}

void SPI_Write(u8 Data)
{
    SPI_Transfer(Data);
}

u8 SPI_Read(void)
{
return SPI_Transfer(0xFF);
}
