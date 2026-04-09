#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

void I2C_Master_Init(u32 Clock) {

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_INPUT);


    SSPCON = 0x28;


    SSPADD = (u8)((4000000 / (4 * Clock)) - 1);


    SSPSTAT = 0x80;
}

void I2C_Master_Wait(void) {

    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Start(void) {
    I2C_Master_Wait();
    SET_BIT(SSPCON2, SEN);
}

void I2C_Master_RepeatedStart(void) {
    I2C_Master_Wait();
    SET_BIT(SSPCON2, RSEN);
}

void I2C_Master_Stop(void) {
    I2C_Master_Wait();
    SET_BIT(SSPCON2, PEN);
}

void I2C_Master_Write(u8 Data) {
    I2C_Master_Wait();
    SSPBUF = Data;
}

u8 I2C_Master_Read(u8 Ack) {
    u8 local_data;
    I2C_Master_Wait();

    SET_BIT(SSPCON2, RCEN);

    I2C_Master_Wait();
    local_data = SSPBUF;

    I2C_Master_Wait();

    if(Ack) CLR_BIT(SSPCON2, ACKDT);
    else    SET_BIT(SSPCON2, ACKDT);

    SET_BIT(SSPCON2, ACKEN);

    return local_data;
}