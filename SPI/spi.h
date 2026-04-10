// Purpose: Lists SPI communication functions

#ifndef SPI_H
#define SPI_H

#include "std_types.h"
#include "pic_config.h"

void SPI_MasterInit(void);              // Setup as controller
void SPI_SlaveInit(void);               // Setup as responder
uint8 SPI_Transfer(uint8 data);         // Send and receive at same time
void SPI_Write(uint8 data);             // Send only
uint8 SPI_Read(void);                   // Receive only

#endif