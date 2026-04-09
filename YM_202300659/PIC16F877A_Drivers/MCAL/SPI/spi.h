/*
 * spi.h
 * MCAL - SPI Driver Interface for PIC16F877A
 * SCK=RC3, SDO=RC5(MOSI), SDI=RC4(MISO), SS=RA5
 */

#ifndef SPI_H
#define SPI_H

typedef unsigned char u8;

/* =====================================================
 * Type Definitions
 * ===================================================== */

typedef enum {
    SPI_MODE_MASTER = 0,
    SPI_MODE_SLAVE  = 1
} SPI_Mode_t;

typedef enum {
    SPI_CLK_FOSC_4  = 0x00,   /* 1 MHz  @ 4MHz Fosc */
    SPI_CLK_FOSC_16 = 0x01,   /* 250kHz @ 4MHz Fosc */
    SPI_CLK_FOSC_64 = 0x02    /* 62.5kHz@ 4MHz Fosc */
} SPI_ClkSpeed_t;

/* SPI Mode (CPOL, CPHA) */
typedef enum {
    SPI_CPOL0_CPHA0 = 0,   /* Mode 0: idle low,  sample rising  */
    SPI_CPOL0_CPHA1 = 1,   /* Mode 1: idle low,  sample falling */
    SPI_CPOL1_CPHA0 = 2,   /* Mode 2: idle high, sample falling */
    SPI_CPOL1_CPHA1 = 3    /* Mode 3: idle high, sample rising  */
} SPI_ClkMode_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize SPI as Master or Slave
 * @param  mode    : SPI_MODE_MASTER / SPI_MODE_SLAVE
 * @param  clk     : Clock speed divider (Master only)
 * @param  clkMode : CPOL/CPHA combination
 */
void SPI_Init(SPI_Mode_t mode, SPI_ClkSpeed_t clk, SPI_ClkMode_t clkMode);

/**
 * @brief  Transmit and receive one byte (full-duplex)
 * @param  data : byte to transmit
 * @return      : received byte
 */
u8 SPI_TransceiveByte(u8 data);

/**
 * @brief  Send one byte (ignore received)
 */
void SPI_SendByte(u8 data);

/**
 * @brief  Receive one byte (send dummy 0xFF)
 */
u8 SPI_ReceiveByte(void);

/**
 * @brief  Transmit a buffer of bytes
 * @param  pTxBuf : pointer to data to send
 * @param  len    : number of bytes
 */
void SPI_SendBuffer(const u8 *pTxBuf, u8 len);

/**
 * @brief  Receive a buffer of bytes
 */
void SPI_ReceiveBuffer(u8 *pRxBuf, u8 len);

/**
 * @brief  Assert SS line LOW (select slave)
 */
void SPI_SelectSlave(void);

/**
 * @brief  Deassert SS line HIGH (deselect slave)
 */
void SPI_DeselectSlave(void);

#endif /* SPI_H */
