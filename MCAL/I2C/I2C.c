#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

/* SSPADD value for I2C clock */
/* SSPADD = (FOSC / (4 * I2C_BAUDRATE)) - 1 */
static u8 sspadd_value = (I2C_FOSC / (4UL * I2C_BAUDRATE)) - 1;

void I2C_Init(void)
{
    /* Set RC3/SDA and RC4/SCL as inputs (open-drain) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    /* Initialize SSPADD for I2C clock frequency */
    SSPADD = sspadd_value;

    /* Configure SSPCON for I2C Master mode */
    SSPCON = I2C_MASTER_MODE;

    /* Enable I2C module */
    SET_BIT(SSPCON, SSPEN);

    /* Clear SSPSTAT flags */
    SSPSTAT = 0;
}

void I2C_Start(void)
{
    /* Generate START condition */
    SET_BIT(SSPCON, START);

    /* Wait for START to complete */
    while(GET_BIT(SSPCON, START));
    while(GET_BIT(SSPSTAT, START) == 0);
}

void I2C_Stop(void)
{
    /* Generate STOP condition */
    SET_BIT(SSPCON, STOP);

    /* Wait for STOP to complete */
    while(GET_BIT(SSPCON, STOP));
}

void I2C_Write(u8 Data)
{
    /* Write data to SSPBUF */
    SSPBUF = Data;

    /* Wait for transmission complete */
    while(GET_BIT(SSPSTAT, BF));

    /* Wait for ACK/NACK from slave */
    while(GET_BIT(SSPSTAT, STOP) == 0) {
        if(GET_BIT(SSPCON, CKP)) break;
    }
}

u8 I2C_Read(u8 Ack)
{
    u8 data;

    /* Enable receive mode */
    SET_BIT(SSPCON, CKP);

    /* Wait for data reception */
    while(!GET_BIT(SSPSTAT, BF));

    /* Read data from SSPBUF */
    data = SSPBUF;

    /* Send ACK or NACK */
    if(Ack) {
        CLR_BIT(SSPCON, UA);  /* Send ACK */
    } else {
        SET_BIT(SSPCON, UA);  /* Send NACK */
    }

    /* Wait for ACK/NACK transmission */
    while(GET_BIT(SSPCON, ACKEN));

    return data;
}

u8 I2C_WriteDevice(u8 Address, u8 *Data, u8 Length)
{
    u8 i;

    /* Generate START condition */
    I2C_Start();

    /* Send slave address with WRITE bit (0) */
    I2C_Write((Address << 1) | 0);

    /* Check for ACK from slave */
    if(GET_BIT(SSPSTAT, RW)) {
        I2C_Stop();
        return I2C_ERROR;
    }

    /* Send data bytes */
    for(i = 0; i < Length; i++) {
        I2C_Write(Data[i]);
        if(GET_BIT(SSPSTAT, RW)) {
            I2C_Stop();
            return I2C_ERROR;
        }
    }

    /* Generate STOP condition */
    I2C_Stop();

    return I2C_SUCCESS;
}

u8 I2C_ReadDevice(u8 Address, u8 *Data, u8 Length)
{
    u8 i;

    /* Generate START condition */
    I2C_Start();

    /* Send slave address with READ bit (1) */
    I2C_Write((Address << 1) | 1);

    /* Check for ACK from slave */
    if(GET_BIT(SSPSTAT, RW)) {
        I2C_Stop();
        return I2C_ERROR;
    }

    /* Read data bytes */
    for(i = 0; i < Length; i++) {
        if(i < Length - 1) {
            Data[i] = I2C_Read(1);  /* Send ACK for all but last byte */
        } else {
            Data[i] = I2C_Read(0);  /* Send NACK for last byte */
        }
    }

    /* Generate STOP condition */
    I2C_Stop();

    return I2C_SUCCESS;
}
