#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"


static void I2C_voidWait(void)
{

    while (GET_BIT(PIR1_REG, PIR1_SSPIF) == 0);
    CLR_BIT(PIR1_REG, PIR1_SSPIF);
}


void I2C_voidMasterInit(void)
{

    SET_BIT(TRISC_REG, 3);
    SET_BIT(TRISC_REG, 4);


    MSSP_ADD_REG = I2C_BAUD_RATE_VAL;


    MSSP_CON1_REG = 0x28;


    MSSP_STAT_REG = 0x00;
    MSSP_CON2_REG = 0x00;
}


void I2C_voidStart(void)
{
    CLR_BIT(PIR1_REG, PIR1_SSPIF);
    SET_BIT(MSSP_CON2_REG, CON2_SEN);
    I2C_voidWait();
}


void I2C_voidStop(void)
{
    CLR_BIT(PIR1_REG, PIR1_SSPIF);
    SET_BIT(MSSP_CON2_REG, CON2_PEN);
    I2C_voidWait();
}


void I2C_voidRepeatedStart(void)
{
    CLR_BIT(PIR1_REG, PIR1_SSPIF);
    SET_BIT(MSSP_CON2_REG, CON2_RSEN);
    I2C_voidWait();
}


u8 I2C_u8WriteByte(u8 Copy_u8Data)
{
    CLR_BIT(PIR1_REG, PIR1_SSPIF);
    MSSP_BUF_REG = Copy_u8Data;
    I2C_voidWait();


    return GET_BIT(MSSP_CON2_REG, CON2_ACKSTAT);
}


u8 I2C_u8ReadByte(u8 Copy_u8Ack)
{
    u8 Local_u8Data;


    CLR_BIT(PIR1_REG, PIR1_SSPIF);
    SET_BIT(MSSP_CON2_REG, CON2_RCEN);
    I2C_voidWait();


    Local_u8Data = MSSP_BUF_REG;


    if (Copy_u8Ack == I2C_SEND_ACK)
    {
        CLR_BIT(MSSP_CON2_REG, CON2_ACKDT);
    }
    else
    {
        SET_BIT(MSSP_CON2_REG, CON2_ACKDT);
    }


    SET_BIT(MSSP_CON2_REG, CON2_ACKEN);
    I2C_voidWait();

    return Local_u8Data;
}

void I2C_voidDisable(void)
{
    CLR_BIT(MSSP_CON1_REG, CON1_SSPEN);
}
