#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#include "../../SERVICES/STD_TYPES.h"

/* I2C Configuration */
#define I2C_CLOCK_SPEED I2C_SPEED_100KHZ /* 100 kHz or 400 kHz */

/* Slave Address (if in slave mode) */
#define I2C_SLAVE_ADDRESS 0x50 /* Default slave address */

/* Master/Slave Mode */
#define I2C_MASTER_SLAVE I2C_MODE_MASTER /* Master or Slave */

/* I2C Interrupt Enable */
#define I2C_INTERRUPT_ENABLE 0 /* 1 = enable, 0 = disable */

#endif
