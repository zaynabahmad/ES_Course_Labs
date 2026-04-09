#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Modes (Clock Phase and Polarity) */
#define SPI_MODE_0  0  /* CPOL=0, CPHA=0 */
#define SPI_MODE_1  1  /* CPOL=0, CPHA=1 */
#define SPI_MODE_2  2  /* CPOL=1, CPHA=0 */
#define SPI_MODE_3  3  /* CPOL=1, CPHA=1 */

/* SPI Clock Speed */
#define SPI_FOSC_4    1
#define SPI_FOSC_16   2
#define SPI_FOSC_64   3

void SPI_Init(u8 Mode, u8 ClockSpeed);
void SPI_Write(u8 Data);
u8 SPI_Read(void);
u8 SPI_Transfer(u8 Data);
void SPI_ChipSelect(u8 Pin, u8 State);

#endif
