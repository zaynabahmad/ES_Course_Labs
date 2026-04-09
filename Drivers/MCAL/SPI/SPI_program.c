#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/SPI/SPI_private.h"
#include "../../MCAL/SPI/SPI_interface.h"
#include "../../MCAL/SPI/SPI_config.h"


void SPI_voidInitMaster(void) {
    // SPI pins: RC3=SCK(out), RC4=SDI(in), RC5=SDO(out)
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_PIN_OUTPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_PIN_INPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_PIN_OUTPUT);
    
    // Master, Fosc/4, 8-bit
    SSPCON = 0x20;
    SSPSTAT = 0x00;
}

uint8 SPI_u8Transfer(uint8 Copy_Data) {
    SSPBUF = Copy_Data;
    while(GET_BIT(SSPSTAT, 0) == 0);  // Wait transmission complete
    return SSPBUF;
}