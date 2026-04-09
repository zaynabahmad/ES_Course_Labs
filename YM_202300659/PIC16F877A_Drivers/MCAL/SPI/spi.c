/*
 * spi.c
 * MCAL - SPI Driver Implementation for PIC16F877A
 */

#include "spi.h"
#include "spi_private.h"

void SPI_Init(SPI_Mode_t mode, SPI_ClkSpeed_t clk, SPI_ClkMode_t clkMode)
{
    /* Step 1: Configure I/O pins */
    if(mode == SPI_MODE_MASTER)
    {
        TRISC_REG &= ~(1 << SPI_SCK_BIT);    /* SCK  = output */
        TRISC_REG &= ~(1 << SPI_SDO_BIT);    /* SDO  = output */
        TRISC_REG |=  (1 << SPI_SDI_BIT);    /* SDI  = input  */
        /* SS pin (RA5) as output - manual control */
        TRISA_REG &= ~(1 << SPI_SS_BIT);
        SPI_SS_PORT |= (1 << SPI_SS_BIT);    /* SS idle HIGH  */
    }
    else
    {
        /* Slave mode */
        TRISC_REG |=  (1 << SPI_SCK_BIT);    /* SCK  = input  */
        TRISC_REG |=  (1 << SPI_SDI_BIT);    /* SDI  = input  */
        TRISC_REG &= ~(1 << SPI_SDO_BIT);    /* SDO  = output */
        TRISA_REG |=  (1 << SPI_SS_BIT);     /* SS   = input  */
    }

    /* Step 2: Disable MSSP before configuration */
    SSPCON_REG = 0x00;

    /* Step 3: Configure clock polarity (CPOL) in SSPCON */
    if(clkMode == SPI_CPOL1_CPHA0 || clkMode == SPI_CPOL1_CPHA1)
    {
        SSPCON_REG |= (1 << SSPCON_CKP);     /* Idle HIGH */
    }

    /* Step 4: Configure clock edge (CPHA) in SSPSTAT */
    SSPSTAT_REG = 0x00;
    if(clkMode == SPI_CPOL0_CPHA0 || clkMode == SPI_CPOL1_CPHA0)
    {
        SSPSTAT_REG |= (1 << SSPSTAT_CKE);   /* Transmit on active->idle */
    }
    /* Sample at end of data */
    SSPSTAT_REG &= ~(1 << SSPSTAT_SMP);      /* Sample middle (0) */

    /* Step 5: Set mode bits */
    if(mode == SPI_MODE_MASTER)
    {
        SSPCON_REG |= (clk & 0x03);
    }
    else
    {
        SSPCON_REG |= SPI_SLAVE_SS_EN;       /* SS pin controlled */
    }

    /* Step 6: Enable MSSP */
    SSPCON_REG |= (1 << SSPCON_SSPEN);

    /* Clear buffer */
    (void)SSPBUF_REG;
}

u8 SPI_TransceiveByte(u8 data)
{
    /* Clear interrupt flag */
    PIR1_REG &= ~(1 << PIR1_SSPIF);

    /* Write data to buffer triggers transmission */
    SSPBUF_REG = data;

    /* Wait for transmission complete */
    while(!((PIR1_REG >> PIR1_SSPIF) & 0x01));

    return SSPBUF_REG;
}

void SPI_SendByte(u8 data)
{
    (void)SPI_TransceiveByte(data);
}

u8 SPI_ReceiveByte(void)
{
    return SPI_TransceiveByte(0xFF);   /* Send dummy byte */
}

void SPI_SendBuffer(const u8 *pTxBuf, u8 len)
{
    u8 i;
    for(i = 0; i < len; i++)
    {
        SPI_SendByte(pTxBuf[i]);
    }
}

void SPI_ReceiveBuffer(u8 *pRxBuf, u8 len)
{
    u8 i;
    for(i = 0; i < len; i++)
    {
        pRxBuf[i] = SPI_ReceiveByte();
    }
}

void SPI_SelectSlave(void)
{
    SPI_SS_PORT &= ~(1 << SPI_SS_BIT);   /* Pull SS LOW */
}

void SPI_DeselectSlave(void)
{
    SPI_SS_PORT |= (1 << SPI_SS_BIT);    /* Pull SS HIGH */
}
