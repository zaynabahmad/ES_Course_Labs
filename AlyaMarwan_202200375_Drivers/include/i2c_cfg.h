#ifndef I2C_CFG_H
#define I2C_CFG_H

#define I2C_CLOCK_SPEED     100000UL
#define I2C_FOSC            8000000UL
#define I2C_SSPADD_VALUE    ((I2C_FOSC / (4 * I2C_CLOCK_SPEED)) - 1)

#endif