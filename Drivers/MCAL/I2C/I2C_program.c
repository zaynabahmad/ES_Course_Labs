#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/I2C/I2C_private.h"
#include "../../MCAL/I2C/I2C_interface.h"
#include "../../MCAL/I2C/I2C_config.h"


void I2C_voidInitMaster(uint32 Copy_BaudRate) {
    // MSSP controls RC3(SCL), RC4(SDA)
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_PIN_INPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_PIN_INPUT);
    
    // SSPADD = Fosc/(4*I2C_Baud) - 1
    uint16 sspadd = (8000000UL / (4UL * Copy_BaudRate)) - 1;
    SSPADD = (uint8)sspadd;
    
    // I2C Master mode, 100kHz
    SSPCON = 0x28;
    SSPSTAT = 0x80;  // Slew rate control enabled
}

void I2C_voidStart(void) {
    SET_BIT(SSPCON2, 0);  // SEN=1
    while(GET_BIT(SSPCON2, 0));
}

void I2C_voidWrite(uint8 Copy_Data) {
    SSPBUF = Copy_Data;
    while(GET_BIT(SSPSTAT, 0) == 0);
}

void I2C_voidStop(void) {
    SET_BIT(SSPCON2, 1);  // PEN=1
    while(GET_BIT(SSPCON2, 1));
}