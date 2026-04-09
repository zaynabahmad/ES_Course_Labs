#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit(void)
{

    CLR_BIT(TRISC_REG, 3);
    SET_BIT(TRISC_REG, 4);
    CLR_BIT(TRISC_REG, 5);


    MSSP_STAT_REG = (SPI_SMP_VALUE << 7) | (SPI_CKE_VALUE << 6);


    MSSP_CTRL1_REG = (1 << 5) | (SPI_CKP_VALUE << 4) | (SPI_SPEED_MODE & 0x0F);


    CLR_BIT(PIR1_REG, PIR1_SSPIF);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{

    CLR_BIT(PIR1_REG, PIR1_SSPIF);


    MSSP_DATA_REG = Copy_u8Data;


    while (GET_BIT(MSSP_STAT_REG, STAT_BF) == 0);


    return MSSP_DATA_REG;
}

void SPI_voidWrite(u8 Copy_u8Data)
{
    (void)SPI_u8Transceive(Copy_u8Data);
}

u8 SPI_u8Read(void)
{

    return SPI_u8Transceive(0xFF);
}

void SPI_voidDisable(void)
{
    CLR_BIT(MSSP_CTRL1_REG, CTRL1_SSPEN);
}