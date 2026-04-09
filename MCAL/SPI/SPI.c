#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"

/* ================= MASTER INIT ================= */
void SPI_voidInitMaster(void)
{
    /* 1. Configure Pins */
    SET_BIT(TRISC, RC3); // SCK -> Output
    CLR_BIT(TRISC, RC4); // SDI -> Input
    SET_BIT(TRISC, RC5); // SDO -> Output
    SET_BIT(TRISC, RC2); // SS  -> Output

    /* Deselect slave */
    SET_BIT(PORTC, RC2);

    /* 2. Clear SSPCON */
    SSPCON = 0;

    /* 3. Clock Selection */
#if (SPI_CLOCK == SPI_FOSC_4)
    CLR_BIT(SSPCON, SSPM0);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);

#elif (SPI_CLOCK == SPI_FOSC_16)
    SET_BIT(SSPCON, SSPM0);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);

#elif (SPI_CLOCK == SPI_FOSC_64)
    CLR_BIT(SSPCON, SSPM0);
    SET_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);

#elif (SPI_CLOCK == SPI_TMR2_DIV2)
    SET_BIT(SSPCON, SSPM0);
    SET_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);
#endif

    /* 4. SPI Mode */
#if (SPI_MODE == SPI_MODE0)
    CLR_BIT(SSPCON, CKP);
    SET_BIT(SSPSTAT, CKE);

#elif (SPI_MODE == SPI_MODE1)
    CLR_BIT(SSPCON, CKP);
    CLR_BIT(SSPSTAT, CKE);

#elif (SPI_MODE == SPI_MODE2)
    SET_BIT(SSPCON, CKP);
    SET_BIT(SSPSTAT, CKE);

#elif (SPI_MODE == SPI_MODE3)
    SET_BIT(SSPCON, CKP);
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* 5. Sample at middle */
    CLR_BIT(SSPSTAT, SMP);

    /* 6. Enable SPI */
    SET_BIT(SSPCON, SSPEN);
}

/* ================= SLAVE INIT ================= */
void SPI_voidInitSlave(void)
{
    /* 1. Configure Pins */
    CLR_BIT(TRISC, RC3); // SCK -> Input
    CLR_BIT(TRISC, RC4); // SDI -> Input
    SET_BIT(TRISC, RC5); // SDO -> Output
    CLR_BIT(TRISC, RC2); // SS  -> Input

    /* 2. Slave Mode with SS */
    SSPCON = 0;
    SSPCON |= 0b00000100;

    /* 3. Mode */
#if (SPI_MODE == SPI_MODE0)
    CLR_BIT(SSPCON, CKP);
    SET_BIT(SSPSTAT, CKE);

#elif (SPI_MODE == SPI_MODE1)
    CLR_BIT(SSPCON, CKP);
    CLR_BIT(SSPSTAT, CKE);

#elif (SPI_MODE == SPI_MODE2)
    SET_BIT(SSPCON, CKP);
    SET_BIT(SSPSTAT, CKE);

#elif (SPI_MODE == SPI_MODE3)
    SET_BIT(SSPCON, CKP);
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* 4. Enable SPI */
    SET_BIT(SSPCON, SSPEN);
}

/* ================= TRANSCEIVE ================= */
u8 SPI_u8Transceive(u8 Copy_u8Data)
{
    /* Check Write Collision */
    if (GET_BIT(SSPCON, WCOL))
    {
        CLR_BIT(SSPCON, WCOL);
    }

    /* Send data */
    SSPBUF = Copy_u8Data;

    /* Wait until transfer complete */
    while (GET_BIT(SSPSTAT, BF) == 0);

    /* Check Overflow (Slave) */
    if (GET_BIT(SSPCON, SSPOV))
    {
        CLR_BIT(SSPCON, SSPOV);
    }

    return SSPBUF;
}

/* ================= SS CONTROL ================= */
void SPI_voidSelectSlave(void)
{
    CLR_BIT(PORTC, RC2);
}

void SPI_voidDeselectSlave(void)
{
    SET_BIT(PORTC, RC2);
}