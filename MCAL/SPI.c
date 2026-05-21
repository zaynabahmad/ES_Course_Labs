/**
 * @file    SPI.c
 * @brief   MSSP SPI (master) driver implementation for the PIC16F877A.
 *
 * @details A transfer is a single shift exchange: writing SSPBUF starts eight
 *          clock pulses, and the same register holds the received byte once
 *          BF rises. The driver therefore exposes one transfer call and lets
 *          callers ignore the return value when they only mean to send.
 */
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_cfg.h"
#include "../SERVICES/Macros.h"

/**
 * @brief  Map the configured clock divider to its SSPM3:0 master pattern.
 */
static byte_t u8ClockBits(void)
{
    switch (SPI_CLOCK_DIV)
    {
        case 4u:  return 0x00u;         /* SPI master, SCK = Fosc/4  */
        case 16u: return 0x01u;         /* SPI master, SCK = Fosc/16 */
        case 64u: return 0x02u;         /* SPI master, SCK = Fosc/64 */
        default:  return 0x01u;         /* default to the Fosc/16 rate. */
    }
}

void vSPI_MasterInit(void)
{
    /* Pin directions: SCK and SDO are master-driven, SDI is sampled, and the
     * slave-select line is a plain output we manage ourselves. */
    BIT_LOW(SPI_REG_TRISC, SPI_PIN_SCK);
    BIT_LOW(SPI_REG_TRISC, SPI_PIN_SDO);
    BIT_HIGH(SPI_REG_TRISC, SPI_PIN_SDI);
    BIT_LOW(SPI_REG_TRISC, SPI_SS_PIN);

    vSPI_SlaveSelect(LEVEL_HIGH);       /* start with the device released. */

    /* Mode 0,0: sample at middle, shift on active-to-idle edge. */
    BIT_HIGH(SPI_REG_SSPSTAT, SPI_BIT_CKE);

    /* Load the clock-rate field, then enable the port; CKP left low = idle. */
    SPI_REG_SSPCON = u8ClockBits();
    BIT_HIGH(SPI_REG_SSPCON, SPI_BIT_SSPEN);
}

byte_t u8SPI_Transfer(byte_t u8TxData)
{
    SPI_REG_SSPBUF = u8TxData;          /* writing the buffer starts the clock. */

    /* BF rises when all eight bits have shifted through in both directions. */
    while (BIT_IS_CLEARED(SPI_REG_SSPSTAT, SPI_BIT_BF))
    {
        /* spin */
    }

    return SPI_REG_SSPBUF;              /* reading the buffer also clears BF. */
}

void vSPI_SlaveSelect(eLevel_t eLevel)
{
    switch (eLevel)
    {
        case LEVEL_LOW:  BIT_LOW(SPI_REG_PORTC, SPI_SS_PIN);  break;
        case LEVEL_HIGH: BIT_HIGH(SPI_REG_PORTC, SPI_SS_PIN); break;
        default:         break;
    }
}
