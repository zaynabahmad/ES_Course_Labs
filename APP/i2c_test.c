#include "../SERVICES/STD_TYPES.h"
#include "i2c_test.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

#define EEPROM_ADDR_W   0xA0
#define EEPROM_ADDR_R   0xA1
#define MEM_ADDR_HIGH   0x00
#define MEM_ADDR_LOW    0x10
#define TEST_DATA       0x42

void I2C_TEST_Run(void)
{
    u8 read_data;
    volatile u32 d;

    LED_Init(GPIO_PORTB, GPIO_PIN2);
    LED_Off(GPIO_PORTB, GPIO_PIN2);

    I2C_Init();

    /* Write */
    I2C_Start();
    I2C_Write(EEPROM_ADDR_W);
    I2C_Write(MEM_ADDR_HIGH);
    I2C_Write(MEM_ADDR_LOW);
    I2C_Write(TEST_DATA);
    I2C_Stop();

    /* Wait for EEPROM write cycle */
    for (d = 0; d < 50000; d++);

    /* Read */
    I2C_Start();
    I2C_Write(EEPROM_ADDR_W);
    I2C_Write(MEM_ADDR_HIGH);
    I2C_Write(MEM_ADDR_LOW);
    I2C_Start();      /* repeated start */
    I2C_Write(EEPROM_ADDR_R);
    read_data = I2C_Read(0);
    I2C_Stop();

    if (read_data == TEST_DATA)
        LED_On(GPIO_PORTB, GPIO_PIN2);

    while (1);
}