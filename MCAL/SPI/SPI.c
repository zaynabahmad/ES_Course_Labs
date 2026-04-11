#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "../../SERVICES/BIT_MATH.h"

/* Registers */
#define SSPCON   *((volatile u8*)0x14)
#define SSPSTAT  *((volatile u8*)0x94)
#define SSPBUF   *((volatile u8*)0x13)

/* ============================= */

void SPI_Init(void)
{
#if SPI_MASTER_MODE

    /* Master mode Fosc/16 */
    SET_BIT(SSPCON , SSPM0);
    CLR_BIT(SSPCON , SSPM1);
    CLR_BIT(SSPCON , SSPM2);
    CLR_BIT(SSPCON , SSPM3);

    /* Enable SPI */
    SET_BIT(SSPCON , SSPEN);

#endif
}

/* ============================= */

u8 SPI_Transmit(u8 data)
{
    /* Send data */
    SSPBUF = data;

    /* Wait until transmission complete */
    while(!GET_BIT(SSPSTAT , BF));

    return SSPBUF;  // received data
}