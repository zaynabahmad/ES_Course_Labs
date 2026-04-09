/*
 * spi_slave_app.c
 * SPI Slave Test — PIC16F877A
 *
 * Behavior: Waits for a byte from the SPI master and displays
 *           it on PORTD LEDs.
 */

#include "../pic_config.h"
#include "spi.h"
#include "../GPIO/gpio.h"

int main(void) {
    ADCON1 = 0x06;   /* All digital */

    SPI_Config cfg = {
        .mode  = SPI_SLAVE,
        .clock = SPI_FOSC_4   /* Ignored in slave mode */
    };
    SPI_init(&cfg);

    /* PORTD all outputs for LED display */
    GPIO_setupPortDirection(PORTD_ID, PORT_OUTPUT);
    GPIO_writePort(PORTD_ID, 0x00);

    while (1) {
        /* Wait until a byte has been received (BF flag set by hardware) */
        while (!SSPSTATbits.BF);
        uint8 received = SSPBUF;              /* Reading SSPBUF clears BF */
        GPIO_writePort(PORTD_ID, received);   /* Display on LEDs          */
    }
    return 0;
}
