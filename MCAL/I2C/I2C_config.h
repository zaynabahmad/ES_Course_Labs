#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* I2C Clock Speed = Fosc / (4 * (SSPADD + 1))
   For 100KHz with Fosc=4MHz: SSPADD = (4000000 / (4 * 100000)) - 1 = 9 */
#define I2C_SSPADD_VALUE    9

/* I2C Mode: 0 = Master, 1 = Slave */
#define I2C_MODE_MASTER     0
#define I2C_MODE_SLAVE      1
#define I2C_MODE            I2C_MODE_MASTER

/* Slave Address (used in slave mode) */
#define I2C_SLAVE_ADDRESS   0x50

#endif