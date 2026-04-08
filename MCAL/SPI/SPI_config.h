#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*
 * ── Clock speed ──────────────────────────────────────────────────────
 * Choose ONE:
 *   SPI_MASTER_FOSC_4    →  2   MHz  (@ 8 MHz crystal)
 *   SPI_MASTER_FOSC_16   →  500 kHz
 *   SPI_MASTER_FOSC_64   →  125 kHz
 */
#define SPI_CLOCK_CONFIG     SPI_MASTER_FOSC_16

/*
 * ── SPI Mode (CPOL / CPHA) ───────────────────────────────────────────
 * Mode 0,0  →  CKP=0, CKE=1   (most common: idle low, sample rising)
 * Mode 1,1  →  CKP=1, CKE=0   (idle high, sample rising)
 *
 * Set CKP and CKE individually below:
 */
#define SPI_CKP_CONFIG       0   /* 0 = clock idle LOW,  1 = idle HIGH  */
#define SPI_CKE_CONFIG       1   /* 1 = transmit on active→idle edge    */
#define SPI_SMP_CONFIG       0   /* 0 = sample at middle of output time */

/*
 * ── Chip-Select (SS) pin ─────────────────────────────────────────────
 * Defined as a GPIO port/pin pair.
 * Change to whichever pin your slave CS is wired to.
 */
#define SPI_CS_PORT          GPIO_PORTC   /* RC2 used as CS (software) */
#define SPI_CS_PIN           GPIO_PIN2

#endif /* SPI_CONFIG_H */
