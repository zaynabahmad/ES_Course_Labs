#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_voidInitMaster(void) {
    /* Set SCK (RC3) and SDO (RC5) as Output, SDI (RC4) as Input */
    CLR_BIT(TRISC_REG, 3);
    CLR_BIT(TRISC_REG, 5);
    SET_BIT(TRISC_REG, 4);

    /* SSPSTAT: Sample at end, Transmit on active-to-idle */
    SSPSTAT_REG = 0x80;
    /* SSPCON: Enable SPI, Master Mode, Fosc/4 */
    SSPCON_REG = 0x20;
}

u8 SPI_u8Transceive(u8 copy_u8Data) {
    SSPBUF_REG = copy_u8Data;
    /* Wait for Buffer Full (Bit 0 of SSPSTAT) */
    while(GET_BIT(SSPSTAT_REG, 0) == 0);
    return SSPBUF_REG;
}