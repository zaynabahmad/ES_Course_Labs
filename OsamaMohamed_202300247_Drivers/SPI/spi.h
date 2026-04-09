/*
 * spi.h
 * SPI Driver for PIC16F877A using the MSSP module (SPI mode)
 *
 * Pin mapping (fixed by hardware):
 *   SCK  = RC3        (clock)
 *   SDO  = RC5        (MOSI — Master Out Slave In)
 *   SDI  = RC4        (MISO — Master In Slave Out)
 *   SS   = RA5        (Slave Select — controlled manually by user/app)
 *
 * Notes:
 *   - SPI and I2C share the MSSP module; only one can be active at a time.
 *   - Clock polarity/phase: CKP=0, CKE=1 => Mode 0,0 (most common).
 *   - SPI_sendReceiveByte() simultaneously sends and receives (full-duplex).
 */

#ifndef SPI_H
#define SPI_H

#include "../std_types.h"
#include <xc.h>

typedef enum { SPI_MASTER, SPI_SLAVE } SPI_Mode;

typedef enum {
    SPI_FOSC_4   = 0b00,   /* Fosc/4   (fastest)  */
    SPI_FOSC_16  = 0b01,   /* Fosc/16             */
    SPI_FOSC_64  = 0b10,   /* Fosc/64             */
    SPI_TMR2     = 0b11    /* Timer2 output/2     */
} SPI_MasterClock;

typedef struct {
    SPI_Mode        mode;
    SPI_MasterClock clock;  /* Ignored in slave mode */
} SPI_Config;

void  SPI_init            (const SPI_Config *config);
uint8 SPI_sendReceiveByte (uint8 data);
void  SPI_sendString      (const char *str);
void  SPI_receiveString   (char *buf, uint8 maxLen);

/* Inline SS helpers — SS pin = RA5 */
#define SPI_SS_LOW()    (PORTAbits.RA5 = 0)
#define SPI_SS_HIGH()   (PORTAbits.RA5 = 1)

#endif /* SPI_H */
