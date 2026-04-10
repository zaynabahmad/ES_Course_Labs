#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

/* The PIC requires I2C pins to be configured as inputs; the hardware module takes over */
void I2C_Master_Init(const u32 BaudRate)
{
    /* Set SDA (RC4) and SCL (RC3) as inputs */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    /* Calculate SSPADD for the desired baud rate (assuming FOSC = 4MHz) */
    SSPADD = (u8)((4000000 / (4 * BaudRate)) - 1);

    /* Enable I2C Master Mode */
    SSPCON = 0x28;
    SSPSTAT = 0x00;
}

static void I2C_Wait(void)
{
    /* Wait until all I2C operations are finished */
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04));
}

void I2C_Start(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, 0); /* Set SEN bit to initiate Start condition */
}

void I2C_Stop(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, 2); /* Set PEN bit to initiate Stop condition */
}

void I2C_Write(u8 Data)
{
    I2C_Wait();
    SSPBUF = Data; /* Load data into buffer to transmit */
}
