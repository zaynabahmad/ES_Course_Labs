#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Modes (Clock Polarity / Phase) */
#define SPI_MODE_0  0   /* CKP=0, CKE=0 */
#define SPI_MODE_1  1   /* CKP=0, CKE=1 */
#define SPI_MODE_2  2   /* CKP=1, CKE=0 */
#define SPI_MODE_3  3   /* CKP=1, CKE=1 */

/* SPI Clock Speed — values match hardware SSPM<3:0> bits directly
 * (Previous values 1/2/3 were off by one and mapped to wrong frequencies)
 * PIC16F877A datasheet: SSPM=0000->Fosc/4, 0001->Fosc/16, 0010->Fosc/64 */
#define SPI_FOSC_4    0   /* Fosc/4  = 1 MHz  @ 4 MHz crystal */
#define SPI_FOSC_16   1   /* Fosc/16 = 250kHz @ 4 MHz crystal */
#define SPI_FOSC_64   2   /* Fosc/64 = 62.5kHz @ 4 MHz crystal */

void SPI_Init(u8 Mode, u8 ClockSpeed);
void SPI_Write(u8 Data);
u8   SPI_Read(void);
u8   SPI_Transfer(u8 Data);
void SPI_ChipSelect(u8 Pin, u8 State);

#endif