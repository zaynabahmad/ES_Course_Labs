#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * SPI Master (MSSP) driver for PIC16F877A
 * Pins: SCK=RC3 (output), SDO=RC5 (output), SDI=RC4 (input)
 * SS (chip-select) is managed by the application layer.
 *
 * Active only when MSSP_ACTIVE_MODE == MSSP_MODE_SPI in MSSP_config.h
 */

void SPI_Init(void);
void SPI_Transmit(u8 Data);
u8   SPI_Receive(void);
void SPI_TransmitReceive(u8 TxData, u8 *RxData);

#endif
