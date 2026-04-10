#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/*
 * ── I2C Clock Speed ──────────────────────────────────────────────────
 * Formula:  SSPADD = (Fosc / (4 * I2C_Freq)) - 1
 *
 * @ Fosc = 8 MHz:
 *   100 kHz (Standard) → SSPADD = (8000000 / 400000)  - 1 = 19
 *   400 kHz (Fast)     → SSPADD = (8000000 / 1600000) - 1 =  4
 */
#define I2C_SSPADD_VALUE    19u     /* 100 kHz @ 8 MHz */

#endif /* I2C_CONFIG_H */
