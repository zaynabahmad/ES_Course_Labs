#include "../SERVICES/types.h"
#include "i2c_test.h"
#include "../MCAL/I2C/i2c_interface.h"
#include "../HAL/LED/led_interface.h"
#include "../MCAL/GPIO/gpio_interface.h"

#define EEPROM_WRITE_ADDR   0xA0
#define EEPROM_READ_ADDR    0xA1
#define MEM_ADDR_HIGH       0x00
#define MEM_ADDR_LOW        0x20
#define TEST_VALUE          0x5A

static void BusyWait(u32 cycles)
{
    volatile u32 i;
    for(i = 0; i < cycles; i++);
}

void I2C_Test_Runner(void)
{
    u8 readback;

    LED_Setup(PORTB_ID, PIN2);
    LED_TurnOff(PORTB_ID, PIN2);

    I2C_Configure();

    /* Write to EEPROM */
    I2C_GenerateStart();
    I2C_SendByte(EEPROM_WRITE_ADDR);
    I2C_SendByte(MEM_ADDR_HIGH);
    I2C_SendByte(MEM_ADDR_LOW);
    I2C_SendByte(TEST_VALUE);
    I2C_GenerateStop();

    BusyWait(40000);

    /* Read back */
    I2C_GenerateStart();
    I2C_SendByte(EEPROM_WRITE_ADDR);
    I2C_SendByte(MEM_ADDR_HIGH);
    I2C_SendByte(MEM_ADDR_LOW);
    I2C_GenerateStart();        /* Repeated start */
    I2C_SendByte(EEPROM_READ_ADDR);
    readback = I2C_ReceiveByte(0);  /* NACK */
    I2C_GenerateStop();

    if(readback == TEST_VALUE)
        LED_TurnOn(PORTB_ID, PIN2);

    while(1);
}