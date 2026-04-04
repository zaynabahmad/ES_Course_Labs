#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

/*
 * Initialize SPI in Master mode.
 * Configures RC3 (SCK) and RC5 (SDO) as outputs, RC4 (SDI) as input.
 */
void SPI_MasterInit(void);

/*
 * Send one byte and simultaneously receive one byte (full-duplex).
 * Blocks until transfer is complete.
 * Returns: byte received from slave.
 */
u8 SPI_Transceive(u8 Data);

/*
 * Send one byte (discard received byte).
 */
void SPI_Write(u8 Data);

/*
 * Receive one byte by clocking out a dummy byte (0xFF).
 */
u8 SPI_Read(void);

/* Disable the SSP module */
void SPI_Disable(void);

#endif