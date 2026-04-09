#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"

//Helper function to ensure bus is IDLE before proceeding
void I2C_Wait(void)
{
    // Wait while I2C is transmitting (SSPSTAT bit 2) or any control sequence is in progress (SSPCON2 bottom 5 bits)
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Init(void)
{
    // Configure I2C Pins (RC3 = SCL, RC4 = SDA) as Inputs
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    // Configure MSSP for I2C Master Mode (SSPCON = 0x28)
    SSPCON = 0x28;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    // Set Baud Rate 
    SSPADD = I2C_SSPADD_VAL;
}

void I2C_Start(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, SEN); // Initiate Start Condition
}

void I2C_RepeatedStart(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, RSEN); // Initiate Repeated Start 
}

void I2C_Stop(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, PEN); // Initiate Stop Condition
}

u8 I2C_Write(u8 Data)
{
    I2C_Wait();
    SSPBUF = Data;         // Write data to buffer
    I2C_Wait();
    
    // Return ACKSTAT bit (0 = ACK received, 1 = NACK received)
    return GET_BIT(SSPCON2, ACKSTAT); 
}

u8 I2C_Read_Byte(u8 Send_ACK)
{
    u8 received_data;
    
    I2C_Wait();
    SET_BIT(SSPCON2, RCEN); // Enable Reception 
    
    // Wait until Buffer is Full
    while(GET_BIT(PIR1, SSPIF) == 0); 
    CLR_BIT(PIR1, SSPIF);
    
    received_data = SSPBUF; // Read the byte
    
    // Send ACK or NACK back to the slave
    I2C_Wait();
    if(Send_ACK == 1)
    {
        CLR_BIT(SSPCON2, ACKDT); // 0 means ACK 
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT); // 1 means NACK 
    }
    SET_BIT(SSPCON2, ACKEN); // Send the sequence
    
    return received_data;
}