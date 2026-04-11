#include "SPI_interface.h"
#include "SPI_private.h"
#include "../../SERVICES/BIT_MATH.h"

void MSPI_InitMaster(u8 clock_rate, u8 mode)
{
    /* Master mode pins:
       RC5 = SDO output
       RC4 = SDI input
       RC3 = SCK output
    */
    CLR_BIT(TRISC, 5);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 3);

    SSPCON  = 0x00;
    SSPSTAT = 0x00;

    /* Set SPI Master clock rate: SSPM3:SSPM0 */
    SSPCON |= (clock_rate & 0x03);

    /* Configure clock polarity and phase */
    switch(mode)
    {
        case SPI_MODE0: /* CKP=0, CKE=1 */
            CLR_BIT(SSPCON, CKP_BIT);
            SET_BIT(SSPSTAT, CKE_BIT);
            break;

        case SPI_MODE1: /* CKP=0, CKE=0 */
            CLR_BIT(SSPCON, CKP_BIT);
            CLR_BIT(SSPSTAT, CKE_BIT);
            break;

        case SPI_MODE2: /* CKP=1, CKE=1 */
            SET_BIT(SSPCON, CKP_BIT);
            SET_BIT(SSPSTAT, CKE_BIT);
            break;

        case SPI_MODE3: /* CKP=1, CKE=0 */
            SET_BIT(SSPCON, CKP_BIT);
            CLR_BIT(SSPSTAT, CKE_BIT);
            break;

        default:
            CLR_BIT(SSPCON, CKP_BIT);
            CLR_BIT(SSPSTAT, CKE_BIT);   /* Match lab default: Mode 1 */
            break;
    }

    /* Lab uses SMP = 0 (sample in middle) */
    CLR_BIT(SSPSTAT, SMP_BIT);

    /* Clear flags */
    CLR_BIT(SSPCON, WCOL_BIT);
    CLR_BIT(SSPCON, SSPOV_BIT);
    CLR_BIT(PIR1, SSPIF_BIT);
    (void)SSPBUF;

    /* Enable MSSP in SPI mode */
    SET_BIT(SSPCON, SSPEN_BIT);
}

u8 MSPI_Transfer(u8 tx_data)
{
    u8 rx_data;

    CLR_BIT(PIR1, SSPIF_BIT);
    CLR_BIT(SSPCON, WCOL_BIT);

    SSPBUF = tx_data;

    while(!GET_BIT(PIR1, SSPIF_BIT));

    rx_data = SSPBUF;            /* Reading clears BF */
    CLR_BIT(PIR1, SSPIF_BIT);

    return rx_data;
}

void MSPI_WriteByte(u8 tx_data)
{
    (void)MSPI_Transfer(tx_data);
}