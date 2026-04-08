#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../../SERVICES/BIT_MATH.h"

void SPI_Init(void)
{
#if SPI_MODE == SPI_MODE_MASTER
    /* Master: SCK(RC3)=output, SDO(RC5)=output, SDI(RC4)=input, SS(RA5)=output */
    CLR_BIT(TRISC, 3);   /* SCK output */
    CLR_BIT(TRISC, 5);   /* SDO output */
    SET_BIT(TRISC, 4);   /* SDI input  */

    /* SSPCON: SSPEN=1, SPI Master Fosc/4 */
    SSPCON = 0x20 | SPI_CLOCK_SELECT;

#else
    /* Slave: SCK(RC3)=input, SDO(RC5)=output, SDI(RC4)=input, SS(RA5)=input */
    SET_BIT(TRISC, 3);   /* SCK input */
    CLR_BIT(TRISC, 5);   /* SDO output */
    SET_BIT(TRISC, 4);   /* SDI input */

    /* SSPCON: SSPEN=1, SPI Slave mode */
    SSPCON = 0x24;
#endif
}

u8 SPI_Transceive(u8 Data)
{
    /* Write data to buffer */
    SSPBUF = Data;

    /* Wait until transmission complete (BF flag = bit0 of SSPSTAT) */
    while(!GET_BIT(SSPSTAT, 0));

    /* Return received data */
    return SSPBUF;
}