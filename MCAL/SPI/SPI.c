#include "SPI_Interface.h"

/* =========================================================
   SPI_MasterInit
========================================================= */

void SPI_MasterInit(void)
{
    /* Configure SPI pins via GPIO layer */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);   /* SCK — master drives clock */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);    /* SDI (MISO) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);   /* SDO (MOSI) */

    /* Configure SSPSTAT: SMP and CKE from config */
    SSPSTAT = 0x00;
    if(SPI_SMP_VALUE) { SET_BIT(SSPSTAT, SMP_BIT); } else { CLR_BIT(SSPSTAT, SMP_BIT); }
    if(SPI_CKE_VALUE) { SET_BIT(SSPSTAT, CKE_BIT); } else { CLR_BIT(SSPSTAT, CKE_BIT); }

    /* Configure SSPCON: speed, polarity, enable */
    SSPCON = (SSPCON & ~SSPM_MASK) | (SPI_SPEED_MODE & SSPM_MASK);
    if(SPI_CKP_VALUE) { SET_BIT(SSPCON, CKP_BIT); } else { CLR_BIT(SSPCON, CKP_BIT); }
    SET_BIT(SSPCON, SSPEN_BIT);

    /* Clear interrupt flag */
    CLR_BIT(PIR1, SSPIF_BIT);
}

/* =========================================================
   SPI_Transceive — full-duplex byte exchange
========================================================= */

u8 SPI_Transceive(u8 Data)
{
    CLR_BIT(PIR1, SSPIF_BIT);      /* Clear flag before starting */
    SSPBUF = Data;                  /* Write data — initiates transfer */

    while(!GET_BIT(SSPSTAT, BF_BIT)) { ; }  /* Wait for buffer full */

    CLR_BIT(PIR1, SSPIF_BIT);

    return SSPBUF;
}

/* =========================================================
   SPI_Write — send only
========================================================= */

void SPI_Write(u8 Data)
{
    (void)SPI_Transceive(Data);
}

/* =========================================================
   SPI_Read — receive only (clocks out 0xFF)
========================================================= */

u8 SPI_Read(void)
{
    return SPI_Transceive(0xFF);
}

/* =========================================================
   SPI_Disable
========================================================= */

void SPI_Disable(void)
{
    CLR_BIT(SSPCON, SSPEN_BIT);
}