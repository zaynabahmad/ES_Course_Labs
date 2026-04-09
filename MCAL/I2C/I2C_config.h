#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

#include "../MSSP_config.h"

/* F_CPU = 4 MHz
 *
 * I2C baud rate = Fosc / (4 * (SSPADD + 1))
 *   100 kHz → SSPADD = 4 000 000 / (4 * 100 000) - 1 = 9
 *   400 kHz → SSPADD = 4 000 000 / (4 * 400 000) - 1 = 1.5 → not exact; use 100 kHz
 */
#define I2C_SSPADD_VALUE    9       /* 100 kHz @ 4 MHz */

/* Slew rate control: 1 = disabled (100 kHz standard mode) */
#define I2C_SMP_BIT_VALUE   1

#endif
