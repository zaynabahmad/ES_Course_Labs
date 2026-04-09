#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include "SPI_Config.h"
#include "SPI_Private.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

// Function prototypes for SPI functions
void SPI_Init(void);
void SPI_Write(unsigned char wr_data);
unsigned char SPI_Read(void);
void SPI_Transmit(unsigned char tx_data);
unsigned char SPI_Receive(void);

#endif // SPI_INTERFACE_H