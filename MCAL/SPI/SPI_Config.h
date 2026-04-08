#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* -------------------------------------------------------
 * CPU Frequency
 * ------------------------------------------------------- */
#define FOSC    4000000UL

/* -------------------------------------------------------
 * Mode Select
 * Options : SPI_MASTER_FOSC4  | SPI_MASTER_FOSC16 |
 *           SPI_MASTER_FOSC64 | SPI_MASTER_TMR2   |
 *           SPI_SLAVE_SS_EN   | SPI_SLAVE_SS_DIS
 * Set a Master clock-rate constant to operate as Master.
 * Set a Slave constant to operate as Slave.
 * ------------------------------------------------------- */
#define SPI_SELECTED_MODE   SPI_MASTER_FOSC4

/* -------------------------------------------------------
 * Clock Polarity — CKP
 * 0 → Idle state of SCK is LOW
 * 1 → Idle state of SCK is HIGH
 * ------------------------------------------------------- */
#define SPI_CKP_VALUE   0

/* -------------------------------------------------------
 * Clock Phase (Edge) — CKE
 * 0 → Data sampled on leading  edge (CKE=0 in SSPSTAT)
 * 1 → Data sampled on trailing edge (CKE=1 in SSPSTAT)
 * ------------------------------------------------------- */
#define SPI_CKE_VALUE   0

/* -------------------------------------------------------
 * Input Sample Phase — SMP
 * 0 → Input data sampled at MIDDLE of data output time
 * 1 → Input data sampled at END   of data output time
 * NOTE: Must be 0 in Slave mode (datasheet requirement).
 * ------------------------------------------------------- */
#define SPI_SMP_VALUE   0

/* -------------------------------------------------------
 * Interrupt-Driven Transfer
 * 1 → Enable SSPIE / PEIE / GIE for ISR-based transfers
 * 0 → Polling mode only
 * ------------------------------------------------------- */
#define SPI_INTERRUPT_EN    0

#endif
