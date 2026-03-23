/**
 * @file    spi.c
 * @brief   PIC16F877 SPI Driver Implementation
 */

#include "spi.h"

/*------------------------------------------------------------
 * Internal: decode SPI_ClockMode_t to CKP and CKE values
 *------------------------------------------------------------*/
static void spi_decode_clock_mode(SPI_ClockMode_t mode,
                                   uint8_t *ckp, uint8_t *cke)
{
    switch (mode) {
        case SPI_CLOCK_MODE0:  *ckp = 0u; *cke = 1u; break;  /* CPOL=0, CPHA=0 */
        case SPI_CLOCK_MODE1:  *ckp = 0u; *cke = 0u; break;  /* CPOL=0, CPHA=1 */
        case SPI_CLOCK_MODE2:  *ckp = 1u; *cke = 1u; break;  /* CPOL=1, CPHA=0 */
        case SPI_CLOCK_MODE3:  *ckp = 1u; *cke = 0u; break;  /* CPOL=1, CPHA=1 */
        default:               *ckp = 0u; *cke = 1u; break;
    }
}

/*------------------------------------------------------------
 * SPI_Init
 *------------------------------------------------------------*/
void SPI_Init(const SPI_Config_t *cfg)
{
    uint8_t ckp, cke;
    spi_decode_clock_mode(cfg->clockMode, &ckp, &cke);

    /* Pin directions:
     *  RC3 (SCK)  — output in master, input in slave
     *  RC5 (SDO)  — output always
     *  RC4 (SDI)  — input always
     *  RA5 (/SS)  — input in slave mode with /SS, don't care if disabled
     */
    if (cfg->mode == SPI_MODE_SLAVE_SS || cfg->mode == SPI_MODE_SLAVE_NO_SS) {
        TRISCbits.TRISC3 = 1;    /* SCK input (slave) */
        if (cfg->mode == SPI_MODE_SLAVE_SS) {
            TRISAbits.TRISA5 = 1; /* /SS input         */
        }
    } else {
        TRISCbits.TRISC3 = 0;    /* SCK output (master) */
    }
    TRISCbits.TRISC5 = 0;        /* SDO output */
    TRISCbits.TRISC4 = 1;        /* SDI input  */

    /* Disable MSSP before configuring */
    SSPCONbits.SSPEN = 0;

    /* SSPCON: CKP and SSPM */
    SSPCON = (uint8_t)((ckp << 4) | (uint8_t)(cfg->mode & 0x0Fu));

    /* SSPSTAT: SMP and CKE */
    SSPSTAT = (uint8_t)(((uint8_t)cfg->smp << 7) | (cke << 6));

    /* Clear flags */
    PIR1bits.SSPIF = 0;

    /* Interrupt */
    if (cfg->intEnable == SPI_INT_ENABLE) {
        PIE1bits.SSPIE = 1;
    } else {
        PIE1bits.SSPIE = 0;
    }

    /* Enable SSP */
    SSPCONbits.SSPEN = 1;
}

/*------------------------------------------------------------
 * SPI_TransferByte — full-duplex single byte
 *------------------------------------------------------------*/
uint8_t SPI_TransferByte(uint8_t data)
{
    /* Write to buffer starts transmission */
    SSPBUF = data;

    /* Wait until BF (Buffer Full) is set — transfer complete */
    while (!SSPSTATbits.BF) {
        /* Wait */
    }

    return SSPBUF;   /* Reading clears BF */
}

/*------------------------------------------------------------
 * SPI_TransferBuffer
 *------------------------------------------------------------*/
void SPI_TransferBuffer(const uint8_t *txBuf, uint8_t *rxBuf, uint8_t len)
{
    uint8_t i;
    uint8_t tx, rx;

    for (i = 0u; i < len; i++) {
        tx = (txBuf != ((void*)0)) ? txBuf[i] : 0xFFu;
        rx = SPI_TransferByte(tx);
        if (rxBuf != ((void*)0)) {
            rxBuf[i] = rx;
        }
    }
}

/*------------------------------------------------------------
 * SPI_SendByte / SPI_ReceiveByte
 *------------------------------------------------------------*/
void SPI_SendByte(uint8_t data)
{
    (void)SPI_TransferByte(data);
}

uint8_t SPI_ReceiveByte(void)
{
    return SPI_TransferByte(0xFFu);
}

/*------------------------------------------------------------
 * SPI_Enable / Disable
 *------------------------------------------------------------*/
void SPI_Enable(void)
{
    SSPCONbits.SSPEN = 1;
}

void SPI_Disable(void)
{
    SSPCONbits.SSPEN = 0;
}

/*------------------------------------------------------------
 * SPI_ClearCollision
 *------------------------------------------------------------*/
void SPI_ClearCollision(void)
{
    SSPCONbits.WCOL = 0;
}

/*------------------------------------------------------------
 * Weak callback
 *------------------------------------------------------------*/
void __attribute__((weak)) SPI_TransferComplete_Callback(void) { }

/*============================================================
 * ISR dispatch (standalone)
 *============================================================*/
#ifdef SPI_USE_STANDALONE_ISR
void __interrupt() SPI_ISR(void)
{
    if (PIE1bits.SSPIE && PIR1bits.SSPIF) {
        PIR1bits.SSPIF = 0;
        SPI_TransferComplete_Callback();
    }
}
#endif
