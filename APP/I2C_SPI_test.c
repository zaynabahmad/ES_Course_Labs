#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../MCAL/SPI/SPI_interface.h"

void UART_SendString(const char *str);

void main(void)
{
    u8 read_value;
    u8 test_value = 0xA5;

    UART_Init();
    I2C_Init();
    SPI_InitMaster();

    UART_SendString("I2C/SPI test start\r\n");

    /* I2C test with a 24LC02 EEPROM at address 0x50 */
    I2C_Start();
    I2C_WriteByte(0xA0);      /* device address + write */
    I2C_WriteByte(0x00);      /* memory address */
    I2C_WriteByte(test_value);/* data */
    I2C_Stop();

    Delay_ms(10);

    I2C_Start();
    I2C_WriteByte(0xA1);      /* device address + read */
    read_value = I2C_ReadByte();
    I2C_SendNack();
    I2C_Stop();

    UART_SendString("I2C read: ");
    UART_SendNumber(read_value);
    UART_SendString("\r\n");

    /* SPI loopback test: wire SDO -> SDI in Proteus */
    UART_SendString("SPI transfer: ");
    read_value = SPI_Transfer(test_value);
    UART_SendNumber(read_value);
    UART_SendString("\r\n");

    while (1) {
        Delay_ms(1000);
    }
}
