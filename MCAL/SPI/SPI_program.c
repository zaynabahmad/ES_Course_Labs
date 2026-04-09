#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"

void SPI_voidInitMaster(void) {
    /* Enable SPI Master mode, Clock = Fosc/4 */
    SSPCON = 0x20;
    SSPSTAT = 0x00;

    /* Configure IO pins for Master */
    CLR_BIT(TRISC, 5); /* SDO Output */
    CLR_BIT(TRISC, 3); /* SCK Output */
    SET_BIT(TRISC, 4); /* SDI Input */
}

void SPI_voidInitSlave(void) {
    /* Enable SPI Slave mode, SS pin enabled */
    SSPCON = 0x24;
    SSPSTAT = 0x00;

    /* Configure SS pin as digital */
    ADCON1 = 0x06;

    /* Configure IO pins for Slave */
    CLR_BIT(TRISC, 5); /* SDO Output */
    SET_BIT(TRISC, 3); /* SCK Input */
    SET_BIT(TRISC, 4); /* SDI Input */
    SET_BIT(TRISA, 5); /* SS Input */
}

u8 SPI_u8Transceive(u8 Copy_u8Data) {
    SSPBUF = Copy_u8Data;

    /* Wait until Buffer Full flag is set */
    while (GET_BIT(SSPSTAT, 0) == 0);

    return SSPBUF;
}