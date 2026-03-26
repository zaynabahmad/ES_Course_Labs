#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Clock Rate */
#define SPI_MASTER_FOSC_DIV4      0
#define SPI_MASTER_FOSC_DIV16     1
#define SPI_MASTER_FOSC_DIV64     2
#define SPI_MASTER_TMR2_DIV2      3

/* SPI Modes */
#define SPI_MODE0                 0   /* CKP=0, CKE=1 */
#define SPI_MODE1                 1   /* CKP=0, CKE=0 */
#define SPI_MODE2                 2   /* CKP=1, CKE=1 */
#define SPI_MODE3                 3   /* CKP=1, CKE=0 */

void MSPI_InitMaster(u8 clock_rate, u8 mode);
u8   MSPI_Transfer(u8 tx_data);
void MSPI_WriteByte(u8 tx_data);

#endif