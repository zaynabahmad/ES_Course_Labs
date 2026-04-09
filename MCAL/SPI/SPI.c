#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void SPI_Init(void)
{
    /* Set Clock Polarity */
#if (SPI_CLOCK_POLARITY == 1)
    SET_BIT(SSPCON, CKP);
#else
    CLR_BIT(SSPCON, CKP);
#endif

    /* Set Clock Phase */
#if (SPI_CLOCK_PHASE == 1)
    SET_BIT(SSPSTAT, CKE);
#else
    CLR_BIT(SSPSTAT, CKE);
#endif

    /* Set Data Sampling Phase */
#if (SPI_DATA_SAMPLE == 1)
    SET_BIT(SSPSTAT, SMP);
#else
    CLR_BIT(SSPSTAT, SMP);
#endif

    /* Set SPI Mode */
    SSPCON = (SSPCON & 0xF0) | (SPI_MODE_SELECT & 0x0F);

    /* Enable SSP module (SPI) */
    SET_BIT(SSPCON, SSPEN);
}

u8 SPI_Transfer(u8 Data)
{
    /* Write Data into Buffer */
    SSPBUF = Data;

    /* Wait until transmission is complete */
    while (GET_BIT(SSPSTAT, BF) == 0);

    /* Return received data */
    return SSPBUF;
}
