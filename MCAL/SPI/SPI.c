#include "SPI_Interface.h"

void SPI_Init(void)
{
    /* SCK (RC3) and SDO (RC5) as output, SDI (RC4) as input */
    CLR_BIT(TRISC, SPI_SCK_PIN);
    CLR_BIT(TRISC, SPI_SDO_PIN);
    SET_BIT(TRISC, SPI_SDI_PIN);

    /* SS (RA5) as output, deselect slave */
    CLR_BIT(TRISA, SPI_SS_PIN);
    SET_BIT(PORTA, SPI_SS_PIN);

    /* Set clock polarity (CKP=0 for Mode 0) */
    CLR_BIT(SSPCON, CKP);

    /* Set clock edge (CKE=1 for Mode 0: transmit on active-to-idle) */
    SET_BIT(SSPSTAT, CKE);

    /* SMP=0: input sampled at middle of data output */
    CLR_BIT(SSPSTAT, SMP);

    /* Set SPI clock speed and enable as master */
    SSPCON = (SSPCON & 0xF0) | (SPI_CLOCK & 0x03);

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transceive(u8 Data)
{
    SSPBUF = Data;                     /* Load data to send */
    while (!GET_BIT(SSPSTAT, BF));     /* Wait until transfer complete */
    return SSPBUF;                     /* Return received data */
}

void SPI_SelectSlave(void)
{
    CLR_BIT(PORTA, SPI_SS_PIN);        /* SS low = select */
}

void SPI_DeselectSlave(void)
{
    SET_BIT(PORTA, SPI_SS_PIN);        /* SS high = deselect */
}
