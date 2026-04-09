#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "I2C_interface.h"
#include "I2C_private.h"

static void I2C_voidWait(void) {
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_voidInitMaster(void) {
    /* Set I2C Master Mode */
    SSPCON = 0x28;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    /* Assuming Fosc = 4MHz, Baud Rate = 100kHz */
    /* SSPADD = ((4000000/4)/100000) - 1 = 9 */
    SSPADD = 0x09;

    /* Configure SCL and SDA pins as inputs */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
}

void I2C_voidStart(void) {
    I2C_voidWait();
    SET_BIT(SSPCON2, 0); /* SEN = 1 */
}

void I2C_voidStop(void) {
    I2C_voidWait();
    SET_BIT(SSPCON2, 2); /* PEN = 1 */
}

u8 I2C_u8Write(u8 Copy_u8Data) {
    I2C_voidWait();
    SSPBUF = Copy_u8Data;
    I2C_voidWait();
    return GET_BIT(SSPCON2, 6); /* ACKSTAT */
}