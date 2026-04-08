#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H



void I2C_Init(void);

/* ── Bus conditions ── */
void I2C_Start(void);
void I2C_RepeatedStart(void);
void I2C_Stop(void);

unsigned char I2C_SendByte(unsigned char val);

unsigned char I2C_ReceiveByte(unsigned char sendACK);
unsigned char I2C_MasterWrite(unsigned char slaveAddr,
                              unsigned char *val,
                              unsigned char len);

unsigned char I2C_MasterRead(unsigned char slaveAddr,
                             unsigned char *buf,
                             unsigned char len);


unsigned char I2C_WriteRegister(unsigned char slaveAddr,
                                unsigned char regAddr,
                                unsigned char value);


unsigned char I2C_ReadRegister(unsigned char slaveAddr,
                               unsigned char regAddr,
                               unsigned char *error);

#endif /* I2C_INTERFACE_H */
