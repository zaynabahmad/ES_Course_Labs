#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../HAL/LED/LED_interface.h"

#define I2C_LED_PORT    GPIO_PORTA
#define I2C_LED_PIN     GPIO_PIN0
#define PCF8574_ADDR    0x20

#define PATTERN_A       0x55  // Alternate LEDs on
#define PATTERN_B       0xAA  // Opposite LEDs on

void I2C_Test(void)
{
    u8 tx[1];
    u8 result;

    GPIO_Init();
    LED_Init(I2C_LED_PORT, I2C_LED_PIN);
    LED_Off(I2C_LED_PORT, I2C_LED_PIN);

    I2C_Init();

    for(u16 i = 0; i < 5000; i++);  // Bus settle delay

    while(1) {
        tx[0] = PATTERN_A;
        result = I2C_WriteDevice(PCF8574_ADDR, tx, 1);

        result ? LED_On(I2C_LED_PORT, I2C_LED_PIN) : LED_Off(I2C_LED_PORT, I2C_LED_PIN);

        for(u16 i = 0; i < 30000; i++);

        tx[0] = PATTERN_B;
        result = I2C_WriteDevice(PCF8574_ADDR, tx, 1);

        result ? LED_On(I2C_LED_PORT, I2C_LED_PIN) : LED_Off(I2C_LED_PORT, I2C_LED_PIN);

        for(u16 i = 0; i < 30000; i++);
    }
}
