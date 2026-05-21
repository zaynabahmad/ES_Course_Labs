/**
 * @file    app_i2c.h
 * @brief   Entry point for the I2C master application.
 */
#ifndef APP_I2C_H
#define APP_I2C_H

/**
 * @brief  Act as an I2C master: address a slave, write a register/value pair
 *         and report whether each byte was acknowledged. Never returns.
 */
void vApp_I2c(void);

#endif /* APP_I2C_H */
