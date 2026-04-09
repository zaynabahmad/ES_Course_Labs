#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include "SPI_Config.h"
#include "SPI_Private.h"
// Function prototypes for SPI functions
void SPI_Init(void);
void SPI_Write(unsigned char data);
unsigned char SPI_Read(void);
void SPI_Transmit(unsigned char data);
unsigned char SPI_Receive(void);

#endif // SPI_INTERFACE_H