/*
 * i2c_test.h
 * APP Layer - I2C Test Declarations
 */

#ifndef I2C_TEST_H
#define I2C_TEST_H

typedef unsigned char u8;

void I2C_Test_Init(void);
void I2C_Test_BusScan(void);
void I2C_Test_PCF8574(void);
void I2C_Test_LM75_Temperature(void);
void I2C_Test_EEPROM(void);
void I2C_Test_Run(void);

#endif /* I2C_TEST_H */
