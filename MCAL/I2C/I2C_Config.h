#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#define FOSC          4000000UL
#define I2C_BAUDRATE  100000UL

/* SSPADD = (Fosc / (4 * Baud)) - 1 */
#define I2C_SSPADD_VALUE  ((FOSC / (4UL * I2C_BAUDRATE)) - 1)

#endif
