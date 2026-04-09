#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#include "../MSSP_config.h"

/* SPI Master clock speed:
 * SSPM<3:0> = 0000 → Fosc/4  = 1 MHz  (default)
 * SSPM<3:0> = 0001 → Fosc/16 = 250 kHz
 * SSPM<3:0> = 0010 → Fosc/64 = 62.5 kHz
 * SSPM<3:0> = 0011 → TMR2/2
 */
#define SPI_SSPM_BITS   0x00    /* Fosc/4 = 1 MHz SPI clock */

/* Clock polarity: 0 = idle low (SPI mode 0/1), 1 = idle high (SPI mode 2/3) */
#define SPI_CKP         0

/* Clock edge: 1 = transmit on active-to-idle (SPI mode 0/2) */
#define SPI_CKE         1

/* Sample point: 0 = middle of data (standard) */
#define SPI_SMP         0

#endif
