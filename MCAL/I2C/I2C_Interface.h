#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "I2C_Config.h"
#include "I2C_Private.h"

#define _XTAL_FREQ 8e6
#define Address 00000000

// PIR, PIE, INTCON
#define GIE_BIT 7
#define PEIE_BIT 6

#define SSPIF_BIT 3
#define SSPIE_BIT 3

// SSPCON
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

// SSPADD

// SSPSTAT
#define GIE_BIT 7
#define INTE_BIT 4
#define INTF_BIT 1

void I2C_Wait(void);
void I2C_Master_Init(u8 BaudRate);
void I2C_Slave_Init(void);

void I2C_Start(void);
void I2C_Restart(void);

void I2C_ACK(void);
void I2C_NACK(void);

unsigned char I2C_Write(unsigned char Data);
unsigned char I2C_Read_Byte(void);

void I2C_SetCallback(void (*Callback)(u8));
void I2C_ISR(void);

#endif
