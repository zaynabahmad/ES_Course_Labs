#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "I2C_private.h"
#include "I2C_interface.h"

void I2C_voidMasterInit(void) {
    /* Set SCL and SDA pins to input mode as required by I2C hardware */
    SET_BIT(TRISC_REG, 3);
    SET_BIT(TRISC_REG, 4);

    /* Enable I2C Master mode and turn on the Synchronous Serial Port */
    SSPCON_REG = 0x28;

    /* Set clock to 100kHz. Formula: SSPADD = (Fosc / (4 * DesiredSpeed)) - 1 */
    /* For 8MHz clock: (8,000,000 / 400,000) - 1 = 19 (0x13) */
    SSPADD_REG = 0x13;

    /* Clear status register to start fresh */
    SSPSTAT_REG = 0x00;
}

void I2C_voidMasterStart(void) {

    SET_BIT(SSPCON2_REG, 0);
    /* Wait for the hardware to pull the line back down (Start finished) */
    while(GET_BIT(SSPCON2_REG, 0) == 1);
}

void I2C_voidMasterStop(void) {

    SET_BIT(SSPCON2_REG, 2);
    /* Wait until the stop sequence is fully completed */
    while(GET_BIT(SSPCON2_REG, 2) == 1);
}

void I2C_voidMasterWrite(u8 copy_u8Data) {
    /* Load the data into the buffer to trigger transmission */
    SSPBUF_REG = copy_u8Data;
    /* Wait for the 'Buffer Full' bit to clear (Transmission done) */
    while(GET_BIT(SSPSTAT_REG, 0) == 1);
}