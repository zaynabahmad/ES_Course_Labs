#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* 100kHz I2C @ 8MHz -> SSPADD = 19 */
#define I2C_FOSC            8000000UL
#define I2C_FREQUENCY       100000UL
#define I2C_SSPADD_VALUE    ((u8)((I2C_FOSC / (4UL * I2C_FREQUENCY)) - 1UL))

#endif
