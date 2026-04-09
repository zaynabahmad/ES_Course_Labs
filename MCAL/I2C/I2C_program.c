#include "I2C_interface.h"

void I2C_Init(void)
{
    TRISC3_bit = 1; // SCL input
    TRISC4_bit = 1; // SDA input

    SSPCON = 0x28;  // Master mode
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

void I2C_Write(char d)
{
    SSPBUF = d;
    while(!SSPIF_bit);
    SSPIF_bit = 0;
}

char I2C_Read(char ack)
{
    RCEN_bit = 1;
    while(!SSPIF_bit);
    SSPIF_bit = 0;

    if(ack) ACKDT_bit = 0;
    else    ACKDT_bit = 1;

    ACKEN_bit = 1;
    while(ACKEN_bit);

    return SSPBUF;
}