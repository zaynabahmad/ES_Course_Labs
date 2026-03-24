#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void SPI_Init(void)
{
    /* ── Pin directions ──
     * RC3 (SCK)  → output in master
     * RC4 (SDI)  → always input
     * RC5 (SDO)  → output in master                */
    CLR_BIT(TRISC, TRISC3);   /* SCK output */
    SET_BIT(TRISC, TRISC4);   /* SDI input  */
    CLR_BIT(TRISC, TRISC5);   /* SDO output */

    /* ── Build SSPCON value ──       */
    SSPCON = 0x00;   /* clear first */

    /* Clock rate */
#if   SPI_CLOCK_RATE == SPI_FOSC_4
    SSPCON |= 0x00;
#elif SPI_CLOCK_RATE == SPI_FOSC_16
    SSPCON |= 0x01;
#elif SPI_CLOCK_RATE == SPI_FOSC_64
    SSPCON |= 0x02;
#elif SPI_CLOCK_RATE == SPI_TMR2
    SSPCON |= 0x03;
#endif

    /* Clock polarity (CKP) */
#if (SPI_MODE == SPI_MODE2) || (SPI_MODE == SPI_MODE3)
    SET_BIT(SSPCON, SSPCON_CKP);   /* CKP = 1, idle high */
#else
    CLR_BIT(SSPCON, SSPCON_CKP);   /* CKP = 0, idle low  */
#endif

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPCON_SSPEN);

    /* ── SSPSTAT: clock edge (CKE) and sample point (SMP) ── */

    /* Clock edge (CKE) */
#if (SPI_MODE == SPI_MODE0) || (SPI_MODE == SPI_MODE2)
    SET_BIT(SSPSTAT, SSPSTAT_CKE);  /* CKE=1 → transmit on active→idle */
#else
    CLR_BIT(SSPSTAT, SSPSTAT_CKE);  /* CKE=0 → transmit on idle→active */
#endif

    /* Sample point (SMP) */
#if SPI_SAMPLE == SPI_SAMPLE_END
    SET_BIT(SSPSTAT, SSPSTAT_SMP);
#else
    CLR_BIT(SSPSTAT, SSPSTAT_SMP);
#endif
}

/* ── Send one byte, return the simultaneously received byte ── */
u8 SPI_Transceive(u8 data)
{
    /* Clear write collision flag if set */
    CLR_BIT(SSPCON, SSPCON_WCOL);

    SSPBUF = data;                          /* Write → starts clock         */

    while (GET_BIT(SSPSTAT, SSPSTAT_BF) == 0);  /* Wait until buffer full  */

    return SSPBUF;                          /* Read clears BF flag          */
}

/* ── Send a buffer (ignore received bytes) ── */
void SPI_WriteBuffer(u8 *data, u8 len)
{
    u8 i;
    for (i = 0; i < len; i++)
    {
        SPI_Transceive(data[i]);
    }
}

/* ── Receive a buffer (send dummy 0xFF to generate clock) ── */
void SPI_ReadBuffer(u8 *buf, u8 len)
{
    u8 i;
    for (i = 0; i < len; i++)
    {
        buf[i] = SPI_Transceive(0xFF);      /* 0xFF = dummy byte            */
    }
}
