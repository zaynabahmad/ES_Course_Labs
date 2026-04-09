#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_InitMaster(void);
void SPI_InitSlave(void);

/**
 Sends and Receives a byte simultaneously.
 */
u8 SPI_Transceive(u8 Copy_u8Data);

#endif