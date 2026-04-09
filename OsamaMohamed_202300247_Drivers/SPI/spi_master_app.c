#include "../pic_config.h"
#include "spi.h"
#include "../GPIO/gpio.h"

void main() {
    ADCON1  = 0x06;
    TRISD   = 0x00;
    TRISA5_bit = 0;    // SS as output
    RA5_bit    = 1;    // SS high (deselected)

    SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV16,
                       _SPI_DATA_SAMPLE_MIDDLE,
                       _SPI_CLK_IDLE_LOW,
                       _SPI_LOW_2_HIGH);

    uint8 tx = 0;
    while (1) {
        RA5_bit = 0;                  // SS low
        SPI1_Write(tx);               // Send byte
        RA5_bit = 1;                  // SS high
        PORTD   = tx;
        tx++;
        Delay_ms(200);
    }
}