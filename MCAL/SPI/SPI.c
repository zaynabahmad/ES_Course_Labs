#include "SPI_Interface.h"

/* ================= Initialization ================= */

void SPI_Init(void)
{
    /* Disable SSP module before configuring */
    CLR_BIT(SSPCON, SSPEN);

    /* Clear SSPCON mode bits */
    SSPCON &= 0xF0;

#if SPI_MODE == SPI_MASTER
    /* Configure RC3 (SCK) as output, RC4 (SDI) as input, RC5 (SDO) as output */
    SET_BIT(TRISC, 4);     /* SDI = input */
    CLR_BIT(TRISC, 3);     /* SCK = output */
    CLR_BIT(TRISC, 5);     /* SDO = output */

    /* Set Master mode clock rate */
#if   SPI_CLOCK_RATE == SPI_FOSC_4
    CLR_BIT(SSPCON, SSPM3);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM0);
#elif SPI_CLOCK_RATE == SPI_FOSC_16
    CLR_BIT(SSPCON, SSPM3);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM1);
    SET_BIT(SSPCON, SSPM0);
#elif SPI_CLOCK_RATE == SPI_FOSC_64
    CLR_BIT(SSPCON, SSPM3);
    CLR_BIT(SSPCON, SSPM2);
    SET_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM0);
#elif SPI_CLOCK_RATE == SPI_TMR2
    CLR_BIT(SSPCON, SSPM3);
    CLR_BIT(SSPCON, SSPM2);
    SET_BIT(SSPCON, SSPM1);
    SET_BIT(SSPCON, SSPM0);
#endif

#elif SPI_MODE == SPI_SLAVE
    /* Configure RC3 (SCK) as input, RC4 (SDI) as input, RC5 (SDO) as output */
    SET_BIT(TRISC, 4);     /* SDI = input */
    SET_BIT(TRISC, 3);     /* SCK = input */
    CLR_BIT(TRISC, 5);     /* SDO = output */

    /* Slave mode with SS pin control disabled */
    CLR_BIT(SSPCON, SSPM3);
    CLR_BIT(SSPCON, SSPM2);
    SET_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM0);
#endif

    /* Configure clock polarity */
#if SPI_CLOCK_POLARITY == SPI_IDLE_LOW
    CLR_BIT(SSPCON, CKP);
#else
    SET_BIT(SSPCON, CKP);
#endif

    /* Configure clock edge */
#if SPI_CLOCK_EDGE == SPI_TRANSMIT_RISING
    SET_BIT(SSPSTAT, CKE);
#else
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* Sample at middle of data output time */
    CLR_BIT(SSPSTAT, SMP);

    /* Enable SSP module */
    SET_BIT(SSPCON, SSPEN);
}

/* ================= Transmit and Receive 1 Byte ================= */

u8 SPI_Transceive(u8 Data)
{
    /* Clear write collision flag */
    CLR_BIT(SSPCON, WCOL);

    /* Write data to buffer - starts transmission */
    SSPBUF = Data;

    /* Wait until buffer full (transfer complete) */
    while(!GET_BIT(SSPSTAT, BF));

    /* Return received byte */
    return SSPBUF;
}

/* ================= Send Only ================= */

void SPI_SendByte(u8 Data)
{
    SPI_Transceive(Data);
}

/* ================= Receive Only (send dummy) ================= */

u8 SPI_ReceiveByte(void)
{
    return SPI_Transceive(0xFF);
}
