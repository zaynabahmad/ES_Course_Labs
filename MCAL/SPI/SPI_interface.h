#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* --- Configuration Macros --- */
#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

#define SPI_CLOCK_FOSC_4     0b0000
#define SPI_CLOCK_FOSC_16    0b0001
#define SPI_CLOCK_FOSC_64    0b0010
#define SPI_CLOCK_TMR2_2     0b0011

/* --- Function Prototypes --- */
void SPI_Init(void);

/* Single Byte */
u8 SPI_Tranceive(u8 trans_data);

/* Improvement 1: Chip Select Management */
void SPI_SelectSlave(u8 Port, u8 Pin);
void SPI_DeselectSlave(u8 Port, u8 Pin);

/* Improvement 2: Block Transfers (Strings/Arrays) */
void SPI_TransmitBlock(u8* data_out, u8 length);
void SPI_ReceiveBlock(u8* data_in, u8 length);

/* Improvement 3: Interrupts */
void SPI_EnableInterrupt(void);
void SPI_DisableInterrupt(void);
void SPI_SetCallback(void (*Callback)(u8 received_byte));
void SPI_ISR(void); /* Called by Interrupt Manager */

#endif