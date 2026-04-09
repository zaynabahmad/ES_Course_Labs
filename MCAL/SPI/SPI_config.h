#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include "SPI_interface.h" /* For configuration macros */

/*
 * SPI Mode Selection:
 * -------------------
 * Choose the mode based on your slave device's requirements.
 * Mode 0 (CKP=0, CKE=0): Clock Idle Low, data transmitted on falling edge.
 * Mode 1 (CKP=0, CKE=1): Clock Idle Low, data transmitted on rising edge.
 * Mode 2 (CKP=1, CKE=0): Clock Idle High, data transmitted on rising edge.
 * Mode 3 (CKP=1, CKE=1): Clock Idle High, data transmitted on falling edge.
 */
#define SPI_MODE            SPI_MODE_0

/* 
 * SPI Clock Rate Selection (Master Mode Only):
 * -------------------------------------------
 * SPI_CLOCK_FOSC_4, SPI_CLOCK_FOSC_16, SPI_CLOCK_FOSC_64, SPI_CLOCK_TMR2_2
 */
#define SPI_MASTER_CLOCK_RATE SPI_CLOCK_FOSC_16

#endif