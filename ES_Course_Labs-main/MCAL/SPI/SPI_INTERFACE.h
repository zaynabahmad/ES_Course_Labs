#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

// ================= Includes =================
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"



// ======================================================
//                    SPI APIs
// ======================================================

// Initialize SPI as Master
void SPI_Master_init(void);

// Initialize SPI as Slave
void SPI_Slave_init(void);

// Send one byte over SPI
void SPI_write(u8 bits);

// Read one byte (polling)
u8 SPI_Read(void);

// Set callback function for SPI interrupt
void SPI_SetCallback(void (*callback)(u8));

// SPI Interrupt Service Routine
void SPI_ISR(void);


#endif // SPI_INTERFACE_H