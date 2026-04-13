#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* I2C Speed Modes */
#define I2C_SPEED_100KHZ        0
#define I2C_SPEED_400KHZ        1

/* I2C Slave Address */
#define I2C_WRITE_BIT           0
#define I2C_READ_BIT            1

/* I2C Initialization */
void I2C_Init(u8 speedMode, u8 slaveAddress);

/* I2C Master Send Start Condition */
void I2C_MasterStart(void);

/* I2C Master Send Stop Condition */
void I2C_MasterStop(void);

/* I2C Master Send Repeated Start */
void I2C_MasterRepeatedStart(void);

/* I2C Master Write Byte */
u8 I2C_MasterWrite(u8 data);

/* I2C Master Read Byte */
u8 I2C_MasterRead(u8 ackRequired);

/* I2C Slave Receive Byte */
u8 I2C_SlaveRead(void);

/* I2C Slave Send Byte */
void I2C_SlaveWrite(u8 data);

/* I2C Get Status */
u8 I2C_GetStatus(void);

/* I2C Set Interrupt Callback */
void I2C_SetCallback(void (*Callback)(u8));

/* I2C Interrupt Service Routine */
void I2C_ISR(void);

#endif
