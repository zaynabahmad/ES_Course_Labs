#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "../GPIO/GPIO_interface.h"

void SPI_voidInitMaster(void) {
    /* 1. Configure Pins using GPIO Driver
       RC5 (SDO) -> Output, RC4 (SDI) -> Input, RC3 (SCK) -> Output */
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);

    /* 2. SSPSTAT: Sample at end, Transmit on active to idle */
    SSPSTAT_REG = 0x80;

    /* 3. SSPCON: Enable SPI, Master mode, Clock = Fosc/4, Idle Low */
    SSPCON_REG = 0x20;
}

u8 SPI_u8Transceive(u8 Copy_u8Data) {
    /* Write data to the buffer */
    SSPBUF_REG = Copy_u8Data;

    /* Wait for transmission to complete (Buffer Full flag) */
    while(GET_BIT(SSPSTAT_REG, BF_BIT) == 0);

    /* Return the received data */
    return SSPBUF_REG;
}