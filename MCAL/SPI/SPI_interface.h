#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void SPI_Init(void);
 

u8   SPI_Transceive(u8 val);
 
void SPI_SendByte(u8 val);
u8   SPI_ReceiveByte(void);
 
void SPI_SendBuffer(const u8 *buf, u8 len);
void SPI_ReceiveBuffer(u8 *buf, u8 len);

void SPI_CS_Enable(void);    /* CS LOW  (assert)   */
void SPI_CS_Disable(void);   /* CS HIGH (deassert) */

#endif /* SPI_INTERFACE_H */
