#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

void I2C_voidInitMaster(uint32 Copy_BaudRate);
void I2C_voidStart(void);
void I2C_voidWrite(uint8 Copy_Data);
void I2C_voidStop(void);

#endif