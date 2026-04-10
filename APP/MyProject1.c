/*
 * main_spi_test.c
 * SPI Driver Test � PIC16F877A @ 8 MHz
 * MikroC PRO for PIC
 *
 * -- Test strategy: SPI loopback -------------------------------------
 *   Physically connect RC5 (SDO/MOSI) to RC4 (SDI/MISO) with a wire.
 *   Every byte the PIC sends comes straight back as the received byte.
 *   Results are reported over UART (9600 baud) so you can watch them
 *   in any serial terminal (e.g. PuTTY, RealTerm, Proteus terminal).
 *
 * -- Wiring -----------------------------------------------------------
 *   RC3 ? SCK   (no external connection needed for loopback)
 *   RC5 ? RC4   (MOSI  shorted to  MISO)
 *   RC2 ? CS    (pulled HIGH internally; not used in loopback test)
 *   RC6 ? TX    (to PC via MAX232 / USB-UART adapter)
 *   RC7 ? RX    (from PC � not used in this test)
 *
 * -- Expected UART output ---------------------------------------------
 *   === SPI Loopback Test ===
 *   [1] Sent=0xA5  Recv=0xA5  PASS
 *   [2] Sent=0x3C  Recv=0x3C  PASS
 *   ...
 *   All 5 tests PASSED
 */

#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../SERVICES/STD_TYPES.h"

/* -- Simple delay -- */
static void Delay_ms(u16 ms)
{
    u16 i, j;
    for (i = 0u; i < ms; i++)
        for (j = 0u; j < 200u; j++) { }
}

/* -- Print one byte as 0xHH over UART -- */
static void UART_SendHex(u8 val)
{
    const u8 hex[] = "0123456789ABCDEF";
    UART_SendString((const u8 *)"0x");
    UART_SendByte(hex[(val >> 4u) & 0x0Fu]);
    UART_SendByte(hex[val & 0x0Fu]);
}

/* -- Run one loopback test, report result, return 1=PASS 0=FAIL -- */
static u8 SPI_LoopbackTest(u8 testNum, u8 sendByte)
{
    u8 received;
    u8 passed;

    SPI_CS_Enable();
    received = SPI_Transceive(sendByte);
    SPI_CS_Disable();

    passed = (received == sendByte) ? 1u : 0u;

    /* "[N] Sent=0xXX  Recv=0xXX  PASS/FAIL" */
    UART_SendString((const u8 *)"[");
    UART_SendNumber((u32)testNum);
    UART_SendString((const u8 *)"] Sent=");
    UART_SendHex(sendByte);
    UART_SendString((const u8 *)"  Recv=");
    UART_SendHex(received);
    UART_SendString((const u8 *)"  ");
    UART_SendString(passed ? (const u8 *)"PASS" : (const u8 *)"FAIL");
    UART_SendNewLine();

    return passed;
}

/* -- Buffer loopback test -- */
static u8 SPI_BufferLoopbackTest(void)
{
    const u8 txBuf[4] = {0x11u, 0x22u, 0x33u, 0x44u};
    u8       rxBuf[4] = {0x00u, 0x00u, 0x00u, 0x00u};
    u8       i;
    u8       allPass = 1u;

    SPI_CS_Enable();
    /* Send and receive byte by byte (full-duplex) */
    for (i = 0u; i < 4u; i++)
    {
        rxBuf[i] = SPI_Transceive(txBuf[i]);
    }
    SPI_CS_Disable();

    UART_SendString((const u8 *)"[6] Buffer test (4 bytes):");
    UART_SendNewLine();

    for (i = 0u; i < 4u; i++)
    {
        u8 pass = (rxBuf[i] == txBuf[i]) ? 1u : 0u;
        if (pass == 0u) { allPass = 0u; }

        UART_SendString((const u8 *)"    Byte[");
        UART_SendNumber((u32)i);
        UART_SendString((const u8 *)"]: Sent=");
        UART_SendHex(txBuf[i]);
        UART_SendString((const u8 *)"  Recv=");
        UART_SendHex(rxBuf[i]);
        UART_SendString((const u8 *)"  ");
        UART_SendString(pass ? (const u8 *)"PASS" : (const u8 *)"FAIL");
        UART_SendNewLine();
    }

    return allPass;
}


/* ----------------------------------------
   MAIN
   ---------------------------------------- */
int main(void)
{
    u8 passCount = 0u;
    u8 result;

    /* Init */
    SPI_Init();
    UART_Init();

    Delay_ms(100u);   /* let everything settle */

    /* Header */
    UART_SendString((const u8 *)"=== SPI Loopback Test ===");
    UART_SendNewLine();
    UART_SendString((const u8 *)"SDO (RC5) shorted to SDI (RC4)");
    UART_SendNewLine();
    UART_SendNewLine();

    /* -- Single-byte tests -- */
    passCount += SPI_LoopbackTest(1u, 0xA5u);   /* 1010 0101 � alternating bits */
    Delay_ms(10u);
    passCount += SPI_LoopbackTest(2u, 0x3Cu);   /* 0011 1100 � another pattern  */
    Delay_ms(10u);
    passCount += SPI_LoopbackTest(3u, 0x00u);   /* all zeros                    */
    Delay_ms(10u);
    passCount += SPI_LoopbackTest(4u, 0xFFu);   /* all ones                     */
    Delay_ms(10u);
    passCount += SPI_LoopbackTest(5u, 0x69u);   /* random byte                  */
    Delay_ms(10u);

    /* -- Buffer test -- */
    result = SPI_BufferLoopbackTest();
    passCount += result;

    /* -- Summary -- */
    UART_SendNewLine();
    UART_SendNumber((u32)passCount);
    UART_SendString((const u8 *)"/6 tests PASSED");
    UART_SendNewLine();

    if (passCount == 6u)
    {
        UART_SendString((const u8 *)">> SPI driver OK");
    }
    else
    {
        UART_SendString((const u8 *)">> CHECK WIRING (SDO-SDI short?)");
    }
    UART_SendNewLine();

    /* -- Continuous live feed -- */
    UART_SendNewLine();
    UART_SendString((const u8 *)"-- Live echo (Fosc/16 clock) --");
    UART_SendNewLine();

    while (1)
    {
        u8 echo;
        SPI_CS_Enable();
        echo = SPI_Transceive(0xABu);
        SPI_CS_Disable();

        UART_SendString((const u8 *)"Echo=");
        UART_SendHex(echo);
        UART_SendNewLine();

        Delay_ms(1000u);
    }
    return 0;
}
