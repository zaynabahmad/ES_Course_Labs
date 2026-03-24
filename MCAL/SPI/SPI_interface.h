#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* ── Clock rate options ── */
#define SPI_FOSC_4      0
#define SPI_FOSC_16     1
#define SPI_FOSC_64     2
#define SPI_TMR2        3

/* ── Mode options ── */
#define SPI_MODE0       0   /* CKP=0, CKE=1 */
#define SPI_MODE1       1   /* CKP=0, CKE=0 */
#define SPI_MODE2       2   /* CKP=1, CKE=1 */
#define SPI_MODE3       3   /* CKP=1, CKE=0 */

/* ── Sample options ── */
#define SPI_SAMPLE_MIDDLE   0
#define SPI_SAMPLE_END      1

/* ── API ── */
void SPI_Init(void);

u8   SPI_Transceive(u8 data);       /* send 1 byte, return received byte */

void SPI_WriteBuffer(u8 *data, u8 len);
void SPI_ReadBuffer (u8 *buf,  u8 len);

#endif
