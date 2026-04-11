#include "../MCAL/I2C/I2C_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/DELAY/DELAY_interface.h"

#define EEPROM_W_ADDR     0xA0
#define EEPROM_R_ADDR     0xA1
#define EEPROM_MEM_ADDR   0x00
#define TEST_DATA         0x5A

static void EEPROM24C02_WriteByte(u8 mem_addr, u8 data)
{
    MI2C_MasterStart();
    MI2C_MasterWrite(EEPROM_W_ADDR);
    MI2C_MasterWrite(mem_addr);
    MI2C_MasterWrite(data);
    MI2C_MasterStop();

    Delay_ms(10);
}

static u8 EEPROM24C02_ReadByte(u8 mem_addr)
{
    u8 data;

    MI2C_MasterStart();
    MI2C_MasterWrite(EEPROM_W_ADDR);
    MI2C_MasterWrite(mem_addr);

    MI2C_MasterRepeatedStart();
    MI2C_MasterWrite(EEPROM_R_ADDR);
    data = MI2C_MasterRead(I2C_NACK);
    MI2C_MasterStop();

    return data;
}

void APP_I2C_Test(void)
{
    u8 read_value;

    LED_Init(GPIO_PORTB, GPIO_PIN0);  /* PASS */
    LED_Init(GPIO_PORTB, GPIO_PIN1);  /* FAIL */

    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);

    MI2C_MasterInit(100000);

    while(1)
    {
        EEPROM24C02_WriteByte(EEPROM_MEM_ADDR, TEST_DATA);
        read_value = EEPROM24C02_ReadByte(EEPROM_MEM_ADDR);

        if(read_value == TEST_DATA)
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
            LED_On(GPIO_PORTB, GPIO_PIN1);
        }

        Delay_ms(1000);
    }
}