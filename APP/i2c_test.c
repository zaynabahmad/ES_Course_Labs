#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

/* Example: Read temperature from a device at address 0x48 */
#define I2C_TEST_SLAVE_ADDR    0x48

void I2C_Test(void)
{
    u8 DataHighByte;
    u8 DataLowByte;

    UART_ServiceRx();

    /* Initialize I2C */
    I2C_Init();

    /* Initialize UART to display results */
    UART_TX_Init();

    /* Write: send device address + write bit, then a register address */
    I2C_Start();
    I2C_SendByte((u8)(I2C_TEST_SLAVE_ADDR << 1) | I2C_WRITE);
    I2C_SendByte(0x00);    /* Register 0: Temperature register */
    I2C_Stop();

    /* Read: send device address + read bit, receive 2 bytes */
    I2C_Start();
    I2C_SendByte((u8)(I2C_TEST_SLAVE_ADDR << 1) | I2C_READ);

    DataHighByte = I2C_ReceiveByte(1);    /* ACK  -> more data coming */
    DataLowByte  = I2C_ReceiveByte(0);    /* NACK -> last byte        */
    I2C_Stop();

    /* Send result over UART */
    UART_Write(DataHighByte);
    UART_Write(DataLowByte);
    UART_Write('\n');
}
