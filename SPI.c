#include "SPI_INTERFACE.h"
#include "SPI_PRIVATE.h"
#include "SPI_CONFIG.h"
#include "../SERVICES/BIT_MATH.h"

void SPI_Init(void)
{
#if SPI_MODE == SPI_MASTER
    /* RC3=SCK output, RC4=SDI input, RC5=SDO output */
    CLR_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);
    /* Set master clock speed in SSPM bits */
    SSPCON = (SSPCON & 0xF0) | (SPI_CLOCK_SPEED & 0x0F);
    /* Sample input at middle of output data */
    CLR_BIT(SSPSTAT, SMP);
#else
    /* RC3=SCK input, RC4=SDI input, RC5=SDO output, RA5=SS input */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);
    SET_BIT(TRISA, 5);
    /* SPI slave mode with SS pin enabled (SSPM = 0100) */
    SSPCON = (SSPCON & 0xF0) | 0x04;
#endif

    /* Clock polarity */
#if SPI_CLOCK_POLARITY == SPI_CKP_HIGH_IDLE
    SET_BIT(SSPCON, CKP);
#else
    CLR_BIT(SSPCON, CKP);
#endif

    /* Clock edge / phase */
#if SPI_CLOCK_PHASE == SPI_CKE_ACTIVE_IDLE
    SET_BIT(SSPSTAT, CKE);
#else
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* Enable SSP module */
    SET_BIT(SSPCON, SSPEN);
}

void SPI_SendByte(u8 data)
{
    SSPBUF = data;
    while(GET_BIT(SSPSTAT, BF) == 0);
    (void)SSPBUF; /* Dummy read to clear BF */
}

u8 SPI_ReceiveByte(void)
{
    SSPBUF = 0xFF; /* Drive clock by writing dummy byte */
    while(GET_BIT(SSPSTAT, BF) == 0);
    return SSPBUF;
}

u8 SPI_ExchangeByte(u8 data)
{
    SSPBUF = data;
    while(GET_BIT(SSPSTAT, BF) == 0);
    return SSPBUF;
}
