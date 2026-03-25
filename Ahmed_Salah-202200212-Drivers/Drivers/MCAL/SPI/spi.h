/**
 * @file    spi.h
 * @brief   PIC16F877 SPI Driver Header (MSSP module in SPI mode)
 * @details Master and Slave modes, all 4 SPI clock polarity/phase combos.
 *
 * Key Registers (DS30292C):
 *   SSPCON  (0x14):
 *     bit7  WCOL    — write collision detect (clear in software)
 *     bit6  SSPOV   — receive overflow (clear in software)
 *     bit5  SSPEN   — SSP enable
 *     bit4  CKP     — clock polarity (0=idle low, 1=idle high)
 *     bit3-0 SSPM   — SSP mode select
 *       0000 SPI Master, Fosc/4
 *       0001 SPI Master, Fosc/16
 *       0010 SPI Master, Fosc/64
 *       0011 SPI Master, TMR2÷2 output
 *       0100 SPI Slave, /SS enabled
 *       0101 SPI Slave, /SS disabled (SS pin=I/O)
 *   SSPSTAT (0x94):
 *     bit7  SMP     — sample point (0=middle, 1=end — master only)
 *     bit6  CKE     — clock edge (0=transmit on active→idle, 1=idle→active)
 *     bit0  BF      — buffer full (receive complete)
 *   SSPBUF  (0x13) — SPI data buffer
 *   PIR1<3> SSPIF  — SSP interrupt flag
 *   PIE1<3> SSPIE  — SSP interrupt enable
 *
 * Pin mapping:
 *   SCK  → RC3 (clock)
 *   SDO  → RC5 (MOSI — Master Out Slave In)
 *   SDI  → RC4 (MISO — Master In  Slave Out)
 *   /SS  → RA5 (slave select, active-low)
 */

#ifndef SPI_H
#define SPI_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * SPI Mode (Master / Slave)
 *============================================================*/
typedef enum {
    SPI_MODE_MASTER_FOSC4  = 0x00,   /* Master, Fosc/4  */
    SPI_MODE_MASTER_FOSC16 = 0x01,   /* Master, Fosc/16 */
    SPI_MODE_MASTER_FOSC64 = 0x02,   /* Master, Fosc/64 */
    SPI_MODE_MASTER_TMR2   = 0x03,   /* Master, TMR2÷2  */
    SPI_MODE_SLAVE_SS      = 0x04,   /* Slave,  /SS pin active */
    SPI_MODE_SLAVE_NO_SS   = 0x05    /* Slave,  /SS ignored   */
} SPI_Mode_t;

/*============================================================
 * Clock Polarity (CKP — idle state)
 *============================================================*/
typedef enum {
    SPI_CKP_IDLE_LOW  = 0,   /* Clock idle = LOW  */
    SPI_CKP_IDLE_HIGH = 1    /* Clock idle = HIGH */
} SPI_CKP_t;

/*============================================================
 * Clock Phase / Edge (CKE)
 *============================================================*/
typedef enum {
    SPI_CKE_ACTIVE_TO_IDLE = 0,   /* Transmit on Active → Idle */
    SPI_CKE_IDLE_TO_ACTIVE = 1    /* Transmit on Idle → Active */
} SPI_CKE_t;

/*============================================================
 * Sample Point (SMP — master only)
 *============================================================*/
typedef enum {
    SPI_SMP_MIDDLE = 0,   /* Input sampled at middle of output */
    SPI_SMP_END    = 1    /* Input sampled at end of output    */
} SPI_SMP_t;

/*============================================================
 * Interrupt Enable
 *============================================================*/
typedef enum {
    SPI_INT_DISABLE = 0,
    SPI_INT_ENABLE  = 1
} SPI_Int_t;

/*============================================================
 * SPI Clock Mode (standard CPOL/CPHA notation)
 *   MODE0: CPOL=0 CKP=0, CPHA=0 CKE=1 (idle low,  leading edge capture)
 *   MODE1: CPOL=0 CKP=0, CPHA=1 CKE=0 (idle low,  trailing edge capture)
 *   MODE2: CPOL=1 CKP=1, CPHA=0 CKE=1 (idle high, leading edge capture)
 *   MODE3: CPOL=1 CKP=1, CPHA=1 CKE=0 (idle high, trailing edge capture)
 *============================================================*/
typedef enum {
    SPI_CLOCK_MODE0 = 0,
    SPI_CLOCK_MODE1,
    SPI_CLOCK_MODE2,
    SPI_CLOCK_MODE3
} SPI_ClockMode_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    SPI_Mode_t      mode;        /* Master/slave and clock divider */
    SPI_ClockMode_t clockMode;   /* CPOL/CPHA (MODE0–MODE3)        */
    SPI_SMP_t       smp;         /* Sample point (master only)     */
    SPI_Int_t       intEnable;   /* SSP interrupt enable            */
} SPI_Config_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize SPI (MSSP in SPI mode)
 * @param  cfg  Pointer to SPI_Config_t
 */
void SPI_Init(const SPI_Config_t *cfg);

/**
 * @brief  Transmit and receive one byte simultaneously
 * @param  data  Byte to send (MOSI)
 * @return Byte received (MISO)
 */
uint8_t SPI_TransferByte(uint8_t data);

/**
 * @brief  Transmit a buffer, receive into rxBuf (full-duplex)
 * @param  txBuf  Transmit buffer (NULL to send 0xFF)
 * @param  rxBuf  Receive  buffer (NULL to discard)
 * @param  len    Number of bytes
 */
void SPI_TransferBuffer(const uint8_t *txBuf, uint8_t *rxBuf, uint8_t len);

/**
 * @brief  Transmit-only convenience (discard MISO)
 * @param  data  Byte to send
 */
void SPI_SendByte(uint8_t data);

/**
 * @brief  Receive-only convenience (transmit 0xFF)
 * @return Received byte
 */
uint8_t SPI_ReceiveByte(void);

/** @brief  Enable SSP module */
void SPI_Enable(void);

/** @brief  Disable SSP module */
void SPI_Disable(void);

/** @brief  Clear write collision flag (WCOL) */
void SPI_ClearCollision(void);

/**
 * @brief  Transfer complete callback (interrupt mode)
 */
void SPI_TransferComplete_Callback(void);

#endif /* SPI_H */
