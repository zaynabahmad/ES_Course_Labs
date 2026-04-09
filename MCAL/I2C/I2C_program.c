#include "I2C_private.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"



void I2C_Init(void)
{
    //  Configure I2C Pins
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT); // SCL
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT); // SDA

    // Clock = 100kHz (Standard)
    // Formula: SSPADD = (Fosc / (4 * Fscl)) - 1
    // For 4MHz ? 100kHz:
    SSPADD_REG = 9;

    //  Configure MSSP
    SSPCON_REG = 0x28; // Master mode

    //  Slew rate OFF (for 100kHz)
    CLR_BIT(SSPSTAT_REG, 7);
}

void I2C_Start(void)
{
    SET_BIT(SSPCON_REG, 0); // SEN

    while(GET_BIT(SSPCON_REG, 0)); // wait
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON_REG, 2); // PEN

    while(GET_BIT(SSPCON_REG, 2));
}

void I2C_Write(u8 _data)
{
    SSPBUF_REG = _data;

    while(!GET_BIT(PIR1_REG, SSPIF_BIT)); // wait

    CLR_BIT(PIR1_REG, SSPIF_BIT);
}

u8 I2C_Read(void)
{
    SET_BIT(SSPCON_REG, 3); // RCEN

    while(!GET_BIT(PIR1_REG, SSPIF_BIT));

    CLR_BIT(PIR1_REG, SSPIF_BIT);

    return SSPBUF_REG;
}
