#include "../../SERVICES/STD_TYPES.h"
#include "I2C_interface.h"

void I2C_Init(void)
{
    // SCL (RC3) & SDA (RC4) inputs
    TRISC3_bit = 1;
    TRISC4_bit = 1;

    // SSPCON: I2C Master mode
    SSPCON = 0x28;

    // SSPADD for 100kHz @ 8MHz
    SSPADD = 19;

    // SSPSTAT
    SSPSTAT = 0x00;
}

void I2C_Start(void)
{
    SEN_bit = 1;
    while(SEN_bit);
}

void I2C_Stop(void)
{
    PEN_bit = 1;
    while(PEN_bit);
}

void I2C_Write (unsigned char u8Data)
{
    SSPBUF = u8Data;         // send data
    while(!SSPIF_bit);      // wait complete
    SSPIF_bit = 0;           // clear flag
}

unsigned char I2C_Read (unsigned char u8Ack)
{
    unsigned char localData;
    RCEN_bit = 1;            // enable receive
    while(!BF_bit);         // wait until buffer full

    localData = SSPBUF;      // Read the data from buffer

    ACKDT_bit = u8Ack;
    ACKEN_bit = 1;
    while(ACKEN_bit);

    return localData;
}