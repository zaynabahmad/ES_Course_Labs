#include "../../SERVICES/Bit_Math.h"
#include "I2C.h"

/* Register Definitions */
#define SSPCON      *((volatile u8*)0x14)
#define SSPBUF      *((volatile u8*)0x13)
#define SSPCON2     *((volatile u8*)0x91)
#define SSPSTAT     *((volatile u8*)0x94)
#define SSPADD      *((volatile u8*)0x93)
#define TRISC       *((volatile u8*)0x87)

/* Private Helper: Wait for I2C Idle */
static void I2C_voidWait(void) {
    /* Wait for: Start, Repeated Start, Stop, Receive, or Acknowledge sequences
       And check if the Transmit Status bit is active */
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04));
}

void I2C_voidMasterInit(void) {
    /* 1. Set RC3 and RC4 as Inputs (Required for I2C) */
    SET_BIT(TRISC, 3); // SCL
    SET_BIT(TRISC, 4); // SDA

    /* 2. SSPCON: Master mode, I2C Enable */
    SSPCON = 0x28; 
    
    /* 3. SSPSTAT: Slew rate disabled for 100kHz */
    SSPSTAT = 0x80; 
    
    /* 4. SSPADD: 100kHz @ 8MHz crystal */
    SSPADD = 0x13; 
}

void I2C_voidStart(void) {
    I2C_voidWait();
    SET_BIT(SSPCON2, 0); // SEN = 1
}

void I2C_voidStop(void) {
    I2C_voidWait();
    SET_BIT(SSPCON2, 2); // PEN = 1
}

void I2C_voidWrite(u8 copy_u8Data) {
    I2C_voidWait();
    SSPBUF = copy_u8Data;
}

u8 I2C_u8Read(u8 copy_u8Ack) {
    u8 local_u8Result;
    I2C_voidWait();
    SET_BIT(SSPCON2, 3); // RCEN = 1 (Enable Receive)
    
    I2C_voidWait();
    local_u8Result = SSPBUF;
    
    /* Handle Acknowledge */
    I2C_voidWait();
    if(copy_u8Ack == 1) CLR_BIT(SSPCON2, 5); // ACKDT = 0 (ACK)
    else                SET_BIT(SSPCON2, 5); // ACKDT = 1 (NACK)
    SET_BIT(SSPCON2, 4); // ACKEN = 1 (Send ACK/NACK)
    
    return local_u8Result;
}