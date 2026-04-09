/*
 * i2c_test.c
 * APP Layer - I2C Driver Test
 *
 * Test Description:
 *   - I2C Master @ 100kHz
 *   - Test 1: Scan all 7-bit addresses (0x08 - 0x77), report found devices
 *   - Test 2: Read/Write to PCF8574 I/O expander (0x20) if present
 *   - Test 3: Read temperature from LM75 sensor (0x48) if present
 *   - Results sent via UART
 */

#include "i2c_test.h"
#include "../MCAL/I2C/i2c.h"
#include "../MCAL/UART/uart.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../SERVICES/services.h"

/* Common I2C device addresses */
#define PCF8574_ADDR    0x20   /* PCF8574 I/O expander (A2=A1=A0=0) */
#define LM75_ADDR       0x48   /* LM75 temperature sensor             */
#define EEPROM_ADDR     0x50   /* 24Cxx EEPROM                        */

void I2C_Test_Init(void)
{
    I2C_MasterInit(I2C_SPEED_100KHZ);
    UART_Init(UART_BAUD_9600);
    UART_SendString((u8*)"=== I2C Test Started ===\r\n");
}

void I2C_Test_BusScan(void)
{
    u8 addr;
    u8 found = 0;
    u8 buf[8];

    UART_SendString((u8*)"Scanning I2C bus (0x08 - 0x77)...\r\n");

    for(addr = 0x08; addr <= 0x77; addr++)
    {
        I2C_Status_t status;

        /* Attempt to address each device - ACK means device present */
        I2C_Start();
        status = I2C_SendByte((u8)(addr << 1));  /* Write address */
        I2C_Stop();

        if(status == I2C_ACK)
        {
            UART_SendString((u8*)"  Found: 0x");
            Utils_UintToHex(addr, buf);
            UART_SendString(buf + 2);
            UART_SendString((u8*)"\r\n");
            found++;
        }
        TIMER0_DelayMs(2);
    }

    if(found == 0)
    {
        UART_SendString((u8*)"  No devices found.\r\n");
    }
    else
    {
        UART_SendString((u8*)"Scan complete. Devices found: ");
        Utils_UintToStr(found, buf);
        UART_SendString(buf);
        UART_SendString((u8*)"\r\n");
    }
}

void I2C_Test_PCF8574(void)
{
    /*
     * PCF8574 test:
     * - Write 0xAA (alternating LEDs on/off)
     * - Read back the port value
     */
    u8 writeData = 0xAA;
    u8 readData  = 0x00;
    u8 buf[8];
    I2C_Status_t status;

    status = I2C_MasterWrite(PCF8574_ADDR, &writeData, 1);
    if(status != I2C_OK)
    {
        UART_SendString((u8*)"PCF8574 Write FAILED (no ACK)\r\n");
        return;
    }

    TIMER0_DelayMs(5);

    status = I2C_MasterRead(PCF8574_ADDR, &readData, 1);
    if(status != I2C_OK)
    {
        UART_SendString((u8*)"PCF8574 Read FAILED\r\n");
        return;
    }

    UART_SendString((u8*)"PCF8574 Write: 0x");
    Utils_UintToHex(writeData, buf);
    UART_SendString(buf + 2);
    UART_SendString((u8*)" | Read: 0x");
    Utils_UintToHex(readData, buf);
    UART_SendString(buf + 2);
    UART_SendString((u8*)"\r\n");
}

void I2C_Test_LM75_Temperature(void)
{
    /*
     * LM75 Temperature Register (0x00):
     * 2-byte read: [15:7] = temp in 0.5C steps (MSB first, 9-bit, 2's complement)
     * Temp(C) = raw_16bit >> 7 (for integer part)
     */
    u8  rawData[2] = {0, 0};
    u16 raw16;
    u16 tempInt;
    u8  buf[8];
    I2C_Status_t status;

    /* Point to temperature register */
    u8 regAddr = 0x00;
    status = I2C_MasterWrite(LM75_ADDR, &regAddr, 1);
    if(status != I2C_OK)
    {
        UART_SendString((u8*)"LM75 not found\r\n");
        return;
    }

    /* Read 2 bytes */
    I2C_MasterRead(LM75_ADDR, rawData, 2);

    raw16   = ((u16)rawData[0] << 8) | rawData[1];
    tempInt = raw16 >> 8;   /* Integer degrees (MSByte = integer part) */

    UART_SendString((u8*)"LM75 Temp: ");
    Utils_UintToStr(tempInt, buf);
    UART_SendString(buf);
    UART_SendString((u8*)" C\r\n");
}

void I2C_Test_EEPROM(void)
{
    /*
     * 24C02 EEPROM test:
     * - Write byte 0xAB to address 0x00
     * - Read back from address 0x00
     */
    u8 writeVal = 0xAB;
    u8 readVal  = 0x00;
    u8 buf[8];

    /* Write: slave addr + mem addr + data */
    I2C_WriteRegister(EEPROM_ADDR, 0x00, writeVal);
    TIMER0_DelayMs(10);   /* EEPROM write cycle time */

    /* Read back using register read */
    readVal = I2C_ReadRegister(EEPROM_ADDR, 0x00);

    UART_SendString((u8*)"EEPROM W: 0x");
    Utils_UintToHex(writeVal, buf);
    UART_SendString(buf + 2);
    UART_SendString((u8*)" R: 0x");
    Utils_UintToHex(readVal, buf);
    UART_SendString(buf + 2);

    if(writeVal == readVal)
    {
        UART_SendString((u8*)" [PASS]\r\n");
    }
    else
    {
        UART_SendString((u8*)" [FAIL]\r\n");
    }
}

void I2C_Test_Run(void)
{
    I2C_Test_Init();

    /* Step 1: Scan bus */
    I2C_Test_BusScan();
    TIMER0_DelayMs(200);

    /* Step 2: PCF8574 I/O expander */
    UART_SendString((u8*)"\r\n--- PCF8574 Test ---\r\n");
    I2C_Test_PCF8574();

    /* Step 3: LM75 Temperature */
    UART_SendString((u8*)"\r\n--- LM75 Temperature ---\r\n");
    I2C_Test_LM75_Temperature();

    /* Step 4: EEPROM */
    UART_SendString((u8*)"\r\n--- EEPROM Test ---\r\n");
    I2C_Test_EEPROM();

    UART_SendString((u8*)"\r\n=== All I2C Tests Done ===\r\n");

    while(1);   /* Halt */
}
