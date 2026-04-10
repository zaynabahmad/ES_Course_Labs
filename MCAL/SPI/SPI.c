#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "../../SERVICES/Bit_Math.h"

static u8 SPI_GetMasterMode(void)
{
#if SPI_CLOCK_DIVIDER == 4U
    return 0x20;
#elif SPI_CLOCK_DIVIDER == 16U
    return 0x21;
#elif SPI_CLOCK_DIVIDER == 64U
    return 0x22;
#else
    #error "Unsupported SPI_CLOCK_DIVIDER"
#endif
}

void SPI_InitMaster(void)
{
    /* SDO and SCK output, SDI input */
    CLR_BIT(TRISC_REG, 5);
    CLR_BIT(TRISC_REG, 6);
    SET_BIT(TRISC_REG, 7);

    SSPCON_REG = SPI_GetMasterMode() | (SPI_CPOL << CKP_BIT) | (1 << SSPEN_BIT);

    if (SPI_CKE)
        SET_BIT(SSPSTAT_REG, CKE_BIT);
    else
        CLR_BIT(SSPSTAT_REG, CKE_BIT);

    if (SPI_SMP)
        SET_BIT(SSPSTAT_REG, SMP_BIT);
    else
        CLR_BIT(SSPSTAT_REG, SMP_BIT);
}

void SPI_InitSlave(void)
{
    /* SDO output, SCK/SDI inputs for slave operation */
    CLR_BIT(TRISC_REG, 5);
    SET_BIT(TRISC_REG, 6);
    SET_BIT(TRISC_REG, 7);

    SSPCON_REG = 0x24 | (SPI_CPOL << CKP_BIT) | (1 << SSPEN_BIT);

    if (SPI_CKE)
        SET_BIT(SSPSTAT_REG, CKE_BIT);
    else
        CLR_BIT(SSPSTAT_REG, CKE_BIT);

    if (SPI_SMP)
        SET_BIT(SSPSTAT_REG, SMP_BIT);
    else
        CLR_BIT(SSPSTAT_REG, SMP_BIT);
}

u8 SPI_Transfer(u8 data)
{
    SSPBUF_REG = data;
    while (!GET_BIT(SSPSTAT_REG, BF_BIT));
    return SSPBUF_REG;
}
