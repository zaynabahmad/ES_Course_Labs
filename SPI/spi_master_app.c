// Purpose: Tests SPI as master (controller)
// Communicates with another PIC running spi_slave_app.c

#include "spi.h"
#include "gpio.h"

void SPI_MasterTest(void) {
    uint8 counter = 0;

    SPI_MasterInit();

    // Setup SS pin (slave select)
    GPIO_SetPinDirection(PORTB_ID, PIN2, OUTPUT);
    GPIO_WritePin(PORTB_ID, PIN2, HIGH);  // Deselect slave

    while(1) {
        GPIO_WritePin(PORTB_ID, PIN2, LOW);   // Select slave

        // Send counter and read what slave sends back
        uint8 received = SPI_Transfer(counter);

        GPIO_WritePin(PORTB_ID, PIN2, HIGH);  // Deselect slave

        counter++;
        __delay_ms(500);
    }
}