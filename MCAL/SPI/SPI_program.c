#include "SPI_interface.h"
#include "SPI_private.h"
#include "../../SERVICES/BIT_MATH.h"

void SPI_MasterInit(u8 mode)
{
    /*
     * SPI Master pins (PIC16F877A MSSP):
     *   RC3 = SCK  (output in master)
     *   RC4 = SDI  (input  always)
     *   RC5 = SDO  (output always)
     *   RA5 = SS   (output, software-controlled)
     */
    CLR_BIT(TRISC, 3);                /* SCK output */
    SET_BIT(TRISC, 4);                /* SDI input  */
    CLR_BIT(TRISC, 5);                /* SDO output */
    CLR_BIT(SPI_SS_TRIS, SPI_SS_PIN); /* SS output */
    SET_BIT(SPI_SS_PORT, SPI_SS_PIN); /* SS high (deselect) */

    /* SPI Master, Fosc/4 → SSPM = 0000 */
    CLR_BIT(SSPCON, SSPCON_SSPM3);
    CLR_BIT(SSPCON, SSPCON_SSPM2);
    CLR_BIT(SSPCON, SSPCON_SSPM1);
    CLR_BIT(SSPCON, SSPCON_SSPM0);

    /* Clock polarity & edge based on mode */
    switch (mode)
    {
    case SPI_MODE_0:
        CLR_BIT(SSPCON, SSPCON_CKP);
        SET_BIT(SSPSTAT, SSPSTAT_CKE);
        break;
    case SPI_MODE_1:
        CLR_BIT(SSPCON, SSPCON_CKP);
        CLR_BIT(SSPSTAT, SSPSTAT_CKE);
        break;
    case SPI_MODE_2:
        SET_BIT(SSPCON, SSPCON_CKP);
        SET_BIT(SSPSTAT, SSPSTAT_CKE);
        break;
    case SPI_MODE_3:
        SET_BIT(SSPCON, SSPCON_CKP);
        CLR_BIT(SSPSTAT, SSPSTAT_CKE);
        break;
    default:
        CLR_BIT(SSPCON, SSPCON_CKP);
        SET_BIT(SSPSTAT, SSPSTAT_CKE);
        break;
    }

    /* Sample at middle of data output (SMP=0 for slave, 0 for master too) */
    CLR_BIT(SSPSTAT, SSPSTAT_SMP);

    /* Enable MSSP module */
    SET_BIT(SSPCON, SSPCON_SSPEN);
}

u8 SPI_Transceive(u8 spiData)
{
    SSPBUF = spiData; /* Write triggers transmission */
    while (!GET_BIT(SSPSTAT, SSPSTAT_BF))
        ;          /* Wait until buffer full      */
    return SSPBUF; /* Read clears BF flag         */
}

void SPI_SS_Low(void) { CLR_BIT(SPI_SS_PORT, SPI_SS_PIN); }
void SPI_SS_High(void) { SET_BIT(SPI_SS_PORT, SPI_SS_PIN); }