#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "../GPIO/GPIO_interface.h"

void I2C_voidInitMaster(u32 Copy_u32Clock) {
    /* 1. Configure SCL (RC3) and SDA (RC4) as Inputs (Required for I2C) */
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);

    /* 2. I2C Master Mode, Clock = Fosc/(4 * (SSPADD + 1)) */
    SSPCON_REG = 0x28;

    /* 3. Set Clock (e.g., 100kHz for 8MHz Fosc) */
    if(Copy_u32Clock == 100000) {
        SSPADD_REG = 19;
    }

    SSPSTAT_REG = 0x80; // Slew rate disabled for 100kHz
}

static void I2C_voidWait(void) {
    /* Wait for MSSP Interrupt Flag (Manual register mapping for PIR1) */
    volatile u8* PIR1_PTR = (volatile u8*)0x0C;
    while(GET_BIT(*PIR1_PTR, 3) == 0);
    CLR_BIT(*PIR1_PTR, 3);
}

void I2C_voidStart(void) {
    SET_BIT(SSPCON2_REG, SEN_BIT);
    I2C_voidWait();
}

void I2C_voidStop(void) {
    SET_BIT(SSPCON2_REG, PEN_BIT);
    I2C_voidWait();
}

void I2C_voidWrite(u8 Copy_u8Data) {
    SSPBUF_REG = Copy_u8Data;
    I2C_voidWait();
}

u8 I2C_u8ReadWithAck(void) {
    u8 Local_u8Data;
    SET_BIT(SSPCON2_REG, RCEN_BIT); // Enable Receive
    I2C_voidWait();
    Local_u8Data = SSPBUF_REG;
    CLR_BIT(SSPCON2_REG, ACKDT_BIT); // Send ACK
    SET_BIT(SSPCON2_REG, ACKEN_BIT);
    I2C_voidWait();
    return Local_u8Data;
}