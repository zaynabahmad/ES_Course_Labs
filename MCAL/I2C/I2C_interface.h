#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#define I2C_ACK     1
#define I2C_NACK    0

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(unsigned char data);
unsigned char I2C_Read(unsigned char send_ack);

#endif