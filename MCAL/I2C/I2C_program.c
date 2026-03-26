#include "I2C_interface.h"
#include "I2C_private.h"
#include "../../SERVICES/BIT_MATH.h"

#define I2C_FOSC_HZ   8000000UL

void MI2C_MasterInit(u32 clock_hz)
{
    /* RC3 = SCL, RC4 = SDA */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    SSPCON  = 0x00;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    /* Standard speed */
    SET_BIT(SSPSTAT, SMP_BIT);
    CLR_BIT(SSPSTAT, CKE_BIT);

    /* Master mode, clock = Fosc / (4 * (SSPADD + 1)) */
    SSPADD = (u8)((I2C_FOSC_HZ / (4UL * clock_hz)) - 1UL);

    /* SSPM3:SSPM0 = 1000 => I2C Master mode */
    CLR_BIT(SSPCON, SSPM0_BIT);
    CLR_BIT(SSPCON, SSPM1_BIT);
    CLR_BIT(SSPCON, SSPM2_BIT);
    SET_BIT(SSPCON, SSPM3_BIT);

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN_BIT);
}

void MI2C_MasterWait(void)
{
    while((SSPCON2 & 0x1F) || GET_BIT(SSPSTAT, RW_BIT));
}

void MI2C_MasterStart(void)
{
    MI2C_MasterWait();
    SET_BIT(SSPCON2, SEN_BIT);
}

void MI2C_MasterRepeatedStart(void)
{
    MI2C_MasterWait();
    SET_BIT(SSPCON2, RSEN_BIT);
}

void MI2C_MasterStop(void)
{
    MI2C_MasterWait();
    SET_BIT(SSPCON2, PEN_BIT);
}

u8 MI2C_MasterWrite(u8 data)
{
    MI2C_MasterWait();
    SSPBUF = data;

    while(GET_BIT(SSPSTAT, BF_BIT));
    MI2C_MasterWait();

    return GET_BIT(SSPCON2, ACKSTAT_BIT);
}

u8 MI2C_MasterRead(u8 ack_state)
{
    u8 received_data;

    MI2C_MasterWait();
    SET_BIT(SSPCON2, RCEN_BIT);

    while(!GET_BIT(SSPSTAT, BF_BIT));

    received_data = SSPBUF;
    MI2C_MasterWait();

    if(ack_state == I2C_ACK)
        CLR_BIT(SSPCON2, ACKDT_BIT);
    else
        SET_BIT(SSPCON2, ACKDT_BIT);

    SET_BIT(SSPCON2, ACKEN_BIT);

    return received_data;
}
