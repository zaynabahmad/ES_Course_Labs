/**
 * @file    uart.h
 * @brief   PIC16F877 UART (USART) Driver Header
 * @details Full-duplex asynchronous mode with optional interrupt support.
 *
 * Key Registers (DS30292C):
 *   TXSTA (0x98):
 *     bit7  CSRC   — clock source (sync mode only)
 *     bit6  TX9    — 9-bit transmit enable
 *     bit5  TXEN   — transmit enable
 *     bit4  SYNC   — 0=async, 1=sync
 *     bit2  BRGH   — high baud rate
 *     bit1  TRMT   — shift register empty flag (read-only)
 *     bit0  TX9D   — 9th data bit
 *   RCSTA (0x18):
 *     bit7  SPEN   — serial port enable (RC6/RC7 configured)
 *     bit6  RX9    — 9-bit receive enable
 *     bit5  SREN   — single receive (sync only)
 *     bit4  CREN   — continuous receive enable
 *     bit3  ADDEN  — address detect (9-bit mode)
 *     bit2  FERR   — framing error
 *     bit1  OERR   — overrun error
 *     bit0  RX9D   — 9th received bit
 *   TXREG (0x19) — transmit data register
 *   RCREG (0x1A) — receive data register (2-deep FIFO)
 *   SPBRG (0x99) — baud rate generator
 *
 * Baud Rate (BRGH=1, async): SPBRG = Fosc / (16 * BaudRate) - 1
 * Baud Rate (BRGH=0, async): SPBRG = Fosc / (64 * BaudRate) - 1
 *
 * Pins: RC6/TX, RC7/RX
 */

#ifndef UART_H
#define UART_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * Baud Rate Mode
 *============================================================*/
typedef enum {
    UART_BRGH_LOW  = 0,   /* Low speed:  SPBRG = Fosc/(64*baud) - 1 */
    UART_BRGH_HIGH = 1    /* High speed: SPBRG = Fosc/(16*baud) - 1 */
} UART_BRGHMode_t;

/*============================================================
 * Data Bits
 *============================================================*/
typedef enum {
    UART_DATABITS_8 = 0,
    UART_DATABITS_9 = 1
} UART_DataBits_t;

/*============================================================
 * Interrupt Enable
 *============================================================*/
typedef enum {
    UART_INT_DISABLE = 0,
    UART_INT_ENABLE  = 1
} UART_Int_t;

/*============================================================
 * Error flags
 *============================================================*/
typedef enum {
    UART_ERROR_NONE     = 0x00,
    UART_ERROR_OVERRUN  = 0x01,
    UART_ERROR_FRAMING  = 0x02
} UART_Error_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    uint32_t       foscHz;      /* Crystal frequency (e.g. 4000000)  */
    uint32_t       baudRate;    /* Desired baud (e.g. 9600)           */
    UART_BRGHMode_t brgh;       /* BRGH=0 low speed / BRGH=1 high     */
    UART_DataBits_t dataBits;   /* 8 or 9 data bits                   */
    UART_Int_t      txIntEn;    /* Transmit interrupt enable           */
    UART_Int_t      rxIntEn;    /* Receive  interrupt enable           */
} UART_Config_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize USART in asynchronous mode
 * @param  cfg  Pointer to UART_Config_t
 */
void UART_Init(const UART_Config_t *cfg);

/**
 * @brief  Transmit a single byte (blocking)
 * @param  data  Byte to transmit
 */
void UART_SendByte(uint8_t data);

/**
 * @brief  Transmit a null-terminated string (blocking)
 * @param  str  Pointer to string in RAM or ROM
 */
void UART_SendString(const char *str);

/**
 * @brief  Transmit a buffer of bytes (blocking)
 * @param  buf  Pointer to data buffer
 * @param  len  Number of bytes to transmit
 */
void UART_SendBuffer(const uint8_t *buf, uint8_t len);

/**
 * @brief  Receive a single byte (blocking, waits for data)
 * @return Received byte
 */
uint8_t UART_ReceiveByte(void);

/**
 * @brief  Check if receive data is available
 * @return 1 if data ready, 0 if not
 */
uint8_t UART_DataAvailable(void);

/**
 * @brief  Check and clear error flags
 * @return Bitmask of UART_Error_t values
 */
uint8_t UART_GetError(void);

/** @brief  Clear overrun error by resetting CREN */
void UART_ClearOverrun(void);

/** @brief  Enable UART (SPEN=1, TXEN=1, CREN=1) */
void UART_Enable(void);

/** @brief  Disable UART */
void UART_Disable(void);

/**
 * @brief  TX interrupt callback — implement in application
 */
void UART_TX_Callback(void);

/**
 * @brief  RX interrupt callback — implement in application
 * @note   Call UART_ReceiveByte() inside callback to read data
 */
void UART_RX_Callback(void);

#endif /* UART_H */
