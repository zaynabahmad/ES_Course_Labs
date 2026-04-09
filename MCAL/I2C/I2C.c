#include "I2C_interface.h"
#include "I2C_private.h"
#include "../../SERVICES/BIT_MATH.h"

/* Internal helper: Wait for I2C bus to be idle */
void I2C_Wait(void) {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Init(uint32 clock_freq) {
    /* 1. Configure I2C pins as inputs */
    /* This should technically be done via GPIO driver to follow rules */
    
    /* 2. Set I2C Master Mode (SSPM3:SSPM0 = 1000) */
    SSPCON = 0x28; /* Enable SSP and set to I2C Master Mode */
    
    /* 3. Set Baud Rate (Assuming 4MHz Fosc)
       SSPADD = (Fosc / (4 * Clock)) - 1
       For 100kHz: (4000000 / (4 * 100000)) - 1 = 9 */
    SSPADD = (4000000 / (4 * clock_freq)) - 1;
    
    SSPSTAT = 0x00;
}

void I2C_Master_Start(void) {
    I2C_Wait();
    SET_BIT(SSPCON2, SEN_BIT); /* */
}

void I2C_Master_Stop(void) {
    I2C_Wait();
    SET_BIT(SSPCON2, PEN_BIT); /* */
}

void I2C_Master_Write(uint8 data) {
    I2C_Wait();
    SSPBUF = data; /* */
}

uint8 I2C_Master_Read(uint8 ack_option) {
    uint8 temp_data;
    I2C_Wait();
    SET_BIT(SSPCON2, RCEN_BIT); /* Enable receive */
    
    I2C_Wait();
    temp_data = SSPBUF; /* Read data */
    
    I2C_Wait();
    /* Set ACK or NACK */
    if(ack_option == I2C_ACK) CLR_BIT(SSPCON2, ACKDT_BIT);
    else SET_BIT(SSPCON2, ACKDT_BIT);
    
    SET_BIT(SSPCON2, ACKEN_BIT); /* Start Ack sequence */
    
    return temp_data;
}