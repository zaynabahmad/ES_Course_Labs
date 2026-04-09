#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

/* MCAL Dependencies */
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

/* Private Helper Function: Waits until the MSSP module is idle */
static void I2C_Wait(void)
{
    /* Wait if:
       1. A Transmit is in progress (R_W bit in SSPSTAT)
       2. Start, Repeated Start, Stop, Receive, or Ack sequence is in progress (lower 5 bits of SSPCON2)
    */
    while ((GET_BIT(SSPSTAT, R_W_BIT) == 1) || (SSPCON2 & 0x1F));
}

void I2C_Init(void)
{
    /* 1. Configure I2C Pins (SCL=RC3, SDA=RC4) as inputs per datasheet */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    /* 2. Set I2C Master Mode (SSPM = 1000) */
    SSPCON = 0b00101000; // Includes enabling SSPEN

    /* 3. Set I2C Clock Speed */
    SSPADD = I2C_SSPADD_VALUE;
    
    /* 4. Ensure bus is clear */
    SSPSTAT = 0x00;

    /* Improvement B: Slew Rate Control Logic */
    #if I2C_CLOCK_SPEED == 400000
        SET_BIT(SSPSTAT, SMP_BIT);  /* Disable slew rate for 400kHz */
    #else
        CLR_BIT(SSPSTAT, SMP_BIT);  /* Enable slew rate for 100kHz */
    #endif
}

void I2C_Start(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, SEN_BIT);
}

void I2C_RepeatedStart(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, RSEN_BIT);
}

void I2C_Stop(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, PEN_BIT);
}

u8 I2C_Write(u8 copy_u8Data)
{
    I2C_Wait();
    SSPBUF = copy_u8Data;
    I2C_Wait();
    
    /* Return the status bit from the slave (0=ACK, 1=NACK) */
    return GET_BIT(SSPCON2, ACKSTAT_BIT);
}

u8 I2C_Read(u8 copy_u8AckOption)
{
    u8 received_data;

    I2C_Wait();
    /* Enable Receive Mode */
    SET_BIT(SSPCON2, RCEN_BIT);

    /* Wait for data to arrive */
    I2C_Wait();
    received_data = SSPBUF;

    /* Configure ACK or NACK to send back to slave */
    if (copy_u8AckOption == I2C_ACK)
        CLR_BIT(SSPCON2, ACKDT_BIT);
    else
        SET_BIT(SSPCON2, ACKDT_BIT);

    /* Start the Acknowledge sequence */
    SET_BIT(SSPCON2, ACKEN_BIT);

    return received_data;
}

/* Improvement C: Block Write Wrapper */
void I2C_WriteBlock(u8 slave_addr, u8* data_array, u8 length)
{
    u8 i;
    I2C_Start();
    /* Send Address + Write Bit */
    I2C_Write((slave_addr << 1) | I2C_DIRECTION_WRITE);
    
    for(i = 0; i < length; i++)
    {
        I2C_Write(data_array[i]);
    }
    I2C_Stop();
}

/* Improvement C: Block Read Wrapper */
void I2C_ReadBlock(u8 slave_addr, u8* data_buffer, u8 length)
{
    u8 i;
    I2C_Start();
    /* Send Address + Read Bit */
    I2C_Write((slave_addr << 1) | I2C_DIRECTION_READ);
    
    for(i = 0; i < length; i++)
    {
        /* Send ACK for all bytes except the last one, then send NACK */
        if(i < (length - 1))
            data_buffer[i] = I2C_Read(I2C_ACK);
        else
            data_buffer[i] = I2C_Read(I2C_NACK);
    }
    I2C_Stop();
}