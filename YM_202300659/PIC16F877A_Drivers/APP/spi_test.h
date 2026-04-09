/*
 * spi_test.h
 * APP Layer - SPI Test Declarations
 */

#ifndef SPI_TEST_H
#define SPI_TEST_H

typedef unsigned char u8;

void SPI_Test_Init(void);
void SPI_Test_Loopback(void);
void SPI_Test_SendBuffer(void);
void SPI_Test_Run(void);

#endif /* SPI_TEST_H */
