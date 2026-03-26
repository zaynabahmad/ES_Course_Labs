#include "SPI_interface.h"
#include "SPI_private.h"
#include "../../SERVICES/BIT_MATH.h"

void MSPI_InitMaster(u8 clock_rate, u8 mode)
{
    /* RC3 = SCK output, RC4 = SDI input, RC5 = SDO output */
    CLR_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    CLR_BIT(TRISC, 5);

    SSPSTAT = 0x00;
    SSPCON  = 0x00;

    /* SPI mode selection */
    switch(mode)
    {
        case SPI_MODE0:
            CLR_BIT(SSPCON, CKP_BIT);
            SET_BIT(SSPSTAT, CKE_BIT);
            break;

        case SPI_MODE1:
            CLR_BIT(SSPCON, CKP_BIT);
            CLR_BIT(SSPSTAT, CKE_BIT);
            break;

        case SPI_MODE2:
            SET_BIT(SSPCON, CKP_BIT);
            SET_BIT(SSPSTAT, CKE_BIT);
            break;

        case SPI_MODE3:
            SET_BIT(SSPCON, CKP_BIT);
            CLR_BIT(SSPSTAT, CKE_BIT);
            break;

        default:
            CLR_BIT(SSPCON, CKP_BIT);
            SET_BIT(SSPSTAT, CKE_BIT);
            break;
    }

    /* Sample bit in middle */
    CLR_BIT(SSPSTAT, SMP_BIT);

    /* Master mode clock select */
    SSPCON |= (clock_rate & 0x03);

    /* Clear status flags */
    CLR_BIT(SSPCON, WCOL_BIT);
    CLR_BIT(SSPCON, SSPOV_BIT);
    CLR_BIT(PIR1, SSPIF_BIT);

    /* Enable MSSP in SPI mode */
    SET_BIT(SSPCON, SSPEN_BIT);
}

u8 MSPI_Transfer(u8 tx_data)
{
    CLR_BIT(PIR1, SSPIF_BIT);
    SSPBUF = tx_data;

    while(!GET_BIT(PIR1, SSPIF_BIT));

    return SSPBUF;
}

void MSPI_WriteByte(u8 tx_data)
{
    (void)MSPI_Transfer(tx_data);
}