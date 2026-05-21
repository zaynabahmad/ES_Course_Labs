/**
 * @file    I2C_cfg.h
 * @brief   Compile-time configuration for the MSSP I2C (master) driver.
 *
 * @details The only board-level choice is the bus clock. SSPADD is derived
 *          from it at init time, so changing this one value retargets the
 *          whole driver.
 */
#ifndef I2C_CFG_H
#define I2C_CFG_H

/** I2C bus clock in hertz. 100000 = standard mode, 400000 = fast mode. */
#define I2C_SCL_FREQ        100000uL

#endif /* I2C_CFG_H */
