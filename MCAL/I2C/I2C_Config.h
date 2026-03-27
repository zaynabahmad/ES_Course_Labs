#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* I2C Baud Rate calculation: SSPADD = (Fosc / (4 * Baud)) - 1 */
/* For 100kHz with 4MHz Fosc: ((4000000 / (4 * 100000)) - 1) = 9 */

#define I2C_SSPADD_VALUE  9

#endif
