#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "SPI_Private.h"
#include "SPI_Config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

/* -------------------------------------------------------
 * Initialization
 * Call SPI_Master_Init() or SPI_Slave_Init() once at
 * startup according to the role of this node.
 * ------------------------------------------------------- */
void SPI_Master_Init(void);
void SPI_Slave_Init(void);

/* -------------------------------------------------------
 * Data Transfer
 *
 * SPI_Write    — transmit one byte (blocking); discards
 *                the simultaneously received byte.
 *
 * SPI_Read     — transmit a dummy 0xFF to generate the
 *                clock and return the received byte.
 *
 * SPI_Transfer — full-duplex: send Data, return the byte
 *                clocked in from the slave simultaneously.
 *                Use this when both sides exchange data.
 * ------------------------------------------------------- */
void SPI_Write(u8 Data);
u8   SPI_Read(void);
u8   SPI_Transfer(u8 Data);

/* -------------------------------------------------------
 * Status
 * Returns 1 when the last transfer is complete (BF set).
 * ------------------------------------------------------- */
u8 SPI_TX_Done(void);

/* -------------------------------------------------------
 * Interrupt-driven support
 * Register a callback; it is invoked from SPI_ISR() with
 * the received byte as argument.  Call SPI_ISR() from the
 * global ISR when SSPIF is detected.
 * ------------------------------------------------------- */
void SPI_SetCallback(void (*Callback)(u8));
void SPI_ISR(void);

#endif
