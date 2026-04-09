#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Clock modes */
#define SPI_MODE_0 0 /* CKP=0, CKE=1 (idle low,  sample rising ) */
#define SPI_MODE_1 1 /* CKP=0, CKE=0 (idle low,  sample falling) */
#define SPI_MODE_2 2 /* CKP=1, CKE=1 (idle high, sample falling) */
#define SPI_MODE_3 3 /* CKP=1, CKE=0 (idle high, sample rising ) */

void SPI_MasterInit(u8 mode);
u8 SPI_Transceive(u8 spiData); /* Send + receive simultaneously */
void SPI_SS_Low(void);
void SPI_SS_High(void);

#endif