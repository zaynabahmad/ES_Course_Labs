                                                       // Purpose: Lists I2C communication functions

#ifndef I2C_H
#define I2C_H

#include "std_types.h"
#include "pic_config.h"

void I2C_Init(uint32 clock_speed);      // Setup I2C (100kHz or 400kHz)
void I2C_Start(void);                    // Begin communication
void I2C_Stop(void);                     // End communication
void I2C_Write(uint8 data);              // Send data
uint8 I2C_Read(uint8 ack);               // Receive data (1=send ack,0=send nack)

#endif