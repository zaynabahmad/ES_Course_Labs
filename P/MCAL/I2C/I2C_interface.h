#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(char d);
char I2C_Read(char ack);  // ack = 1 for ACK, 0 for NACK

#endif