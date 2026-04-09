/*
 * spi_test.c
 * APP Layer - SPI Driver Test
 *
 * Test Description:
 *   - SPI Master @ Fosc/16 (250kHz), Mode 0
 *   - Write 0xAA and read back (loopback: connect SDO->SDI)
 *   - Send incrementing byte, display received on PORTB LEDs
 *   - Simulate slave-select with RA5
 */

#include "spi_test.h"
#include "../MCAL/SPI/spi.h"
#include "../MCAL/UART/uart.h"
#include "../MCAL/TIMER0/timer0.h"
#include "../MCAL/GPIO/gpio.h"
#include "../SERVICES/services.h"

static u8 g_spiTxByte = 0x01;

void SPI_Test_Init(void)
{
    /* Master, Fosc/16, Mode 0 (CPOL=0, CPHA=0) */
    SPI_Init(SPI_MODE_MASTER, SPI_CLK_FOSC_16, SPI_CPOL0_CPHA0);

    /* PORTB as output for received byte display */
    GPIO_SetPortDirection(GPIO_PORTB, 0x00);
    GPIO_WritePort(GPIO_PORTB, 0x00);

    /* UART for results */
    UART_Init(UART_BAUD_9600);
    UART_SendString((u8*)"=== SPI Test Started ===\r\n");
    UART_SendString((u8*)"Connect SDO(RC5) -> SDI(RC4) for loopback\r\n");
}

void SPI_Test_Loopback(void)
{
    u8  received;
    u8  buf[8];

    SPI_SelectSlave();
    received = SPI_TransceiveByte(g_spiTxByte);
    SPI_DeselectSlave();

    /* Display received byte on PORTB */
    GPIO_WritePort(GPIO_PORTB, received);

    /* Send result via UART */
    UART_SendString((u8*)"TX: 0x");
    Utils_UintToHex(g_spiTxByte, buf);
    UART_SendString(buf + 2);    /* Last 2 hex chars = 1 byte */
    UART_SendString((u8*)" | RX: 0x");
    Utils_UintToHex(received, buf);
    UART_SendString(buf + 2);
    UART_SendString((u8*)"\r\n");

    g_spiTxByte <<= 1;
    if(g_spiTxByte == 0) g_spiTxByte = 0x01;
}

void SPI_Test_SendBuffer(void)
{
    u8 txBuf[4] = {0xDE, 0xAD, 0xBE, 0xEF};
    u8 rxBuf[4] = {0};
    u8 i;

    SPI_SelectSlave();
    for(i = 0; i < 4; i++)
    {
        rxBuf[i] = SPI_TransceiveByte(txBuf[i]);
    }
    SPI_DeselectSlave();

    UART_SendString((u8*)"Buffer TX->RX: ");
    for(i = 0; i < 4; i++)
    {
        u8 buf[8];
        Utils_UintToHex(rxBuf[i], buf);
        UART_SendString(buf + 2);
        UART_SendByte(' ');
    }
    UART_SendString((u8*)"\r\n");
}

void SPI_Test_Run(void)
{
    SPI_Test_Init();

    while(1)
    {
        SPI_Test_Loopback();
        TIMER0_DelayMs(300);

        /* Every 5 cycles, do a buffer transfer */
        {
            static u8 cnt = 0;
            cnt++;
            if(cnt >= 5)
            {
                cnt = 0;
                SPI_Test_SendBuffer();
            }
        }
    }
}
