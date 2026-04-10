#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"

#define _XTAL_FREQ 8e6

// SSPCON
#define SSPOV_BIT 6
#define SSPEN_BIT 5
#define CKP_BIT 4
#define SSPM3_BIT 3
#define SSPM2_BIT 2
#define SSPM1_BIT 1
#define SSPM0_BIT 0

// SSPCON2
#define GCEN_BIT 7
#define ACKSTAT_BIT 6
#define ACKDT_BIT 5
#define ACKEN_BIT 4
#define RCEN_BIT 3
#define PEN_BIT 2
#define RSEN_BIT 1
#define SEN_BIT 0

// ADCON1
#define PCFG3_BIT 3
#define PCFG2_BIT 2
#define PCFG1_BIT 1
#define PCFG0_BIT 0

// SSPSTAT
#define SMP_BIT 7
#define CKE_BIT 6
#define BF_BIT 0

// Interrupts
#define GIE_BIT 7
#define PEIE_BIT 6
#define INTE_BIT 4
#define INTF_BIT 1

#define SSPIF_BIT 3
#define SSPIE_BIT 3

void SPI_Wait(void);
void SPI_Master_Init(void);
void SPI_Slave_Init(void);

void SPI_Write(unsigned char Data);
unsigned char SPI_Read_Byte(void);

void SPI_SetCallback(void (*Callback)(u8));
void SPI_ISR(void);

#endif
