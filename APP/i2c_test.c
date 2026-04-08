

#include "../MCAL/I2C/I2C_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../SERVICES/STD_TYPES.h"

/* DS1307 I2C address (7-bit) */
#define DS1307_ADDR     0x68u

/* ── BCD helpers ── */
#define TO_BCD(x)    ((unsigned char)(((x)/10u)<<4u) | ((x)%10u))
#define FROM_BCD(x)  ((unsigned char)(((x)>>4u)*10u)  + ((x)&0x0Fu))

/* ── Delay ── */
static void Delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0u; i < ms; i++)
        for (j = 0u; j < 200u; j++) { }
}

/* ── Send two-digit decimal over UART ── */
static void UART_Send2Digits(unsigned char val)
{
    UART_SendByte((unsigned char)('0' + (val / 10u)));
    UART_SendByte((unsigned char)('0' + (val % 10u)));
}

/* ══════════════════════════════════════════
   TEST 1 – Presence check
   Send address only, check for ACK
   ══════════════════════════════════════════ */
static unsigned char Test_Presence(void)
{
    unsigned char dummy = 0x00u;
    unsigned char result;

    /* MasterWrite with 0 bytes just sends addr+W and checks ACK */
    result = I2C_MasterWrite(DS1307_ADDR, &dummy, 0u);

    UART_SendString((const u8 *)"[1] Presence check ... ");
    if (result == 0u)
    {
        UART_SendString((const u8 *)"PASS (DS1307 ACK'd)");
        UART_SendNewLine();
        return 1u;
    }
    else
    {
        UART_SendString((const u8 *)"FAIL (no ACK - check wiring)");
        UART_SendNewLine();
        return 0u;
    }
}

/* ══════════════════════════════════════════
   TEST 2 – Write time 12:00:00
   ══════════════════════════════════════════ */
static unsigned char Test_Write(void)
{
    unsigned char result;

    /* Seconds reg (0x00): CH=0 (run), seconds=0 */
    result  = I2C_WriteRegister(DS1307_ADDR, 0x00u, TO_BCD(0u));
    /* Minutes reg (0x01) */
    result |= I2C_WriteRegister(DS1307_ADDR, 0x01u, TO_BCD(0u));
    /* Hours reg (0x02): 24h mode (bit6=0), hours=12 */
    result |= I2C_WriteRegister(DS1307_ADDR, 0x02u, TO_BCD(12u));

    UART_SendString((const u8 *)"[2] Write 12:00:00  ... ");
    if (result == 0u)
    {
        UART_SendString((const u8 *)"PASS");
        UART_SendNewLine();
        return 1u;
    }
    else
    {
        UART_SendString((const u8 *)"FAIL (NACK on write)");
        UART_SendNewLine();
        return 0u;
    }
}

/* ══════════════════════════════════════════
   TEST 3 – Read back and verify
   ══════════════════════════════════════════ */
static unsigned char Test_Read(void)
{
    unsigned char err  = 0u;
    unsigned char secs, mins, hrs;
    unsigned char pass = 1u;

    secs = FROM_BCD(I2C_ReadRegister(DS1307_ADDR, 0x00u, &err) & 0x7Fu); /* mask CH bit */
    if (err) { pass = 0u; }
    mins = FROM_BCD(I2C_ReadRegister(DS1307_ADDR, 0x01u, &err));
    if (err) { pass = 0u; }
    hrs  = FROM_BCD(I2C_ReadRegister(DS1307_ADDR, 0x02u, &err) & 0x3Fu); /* mask mode bits */
    if (err) { pass = 0u; }

    /* Verify values match what we wrote (seconds may have ticked by 1) */
    if (mins != 0u || hrs != 12u) { pass = 0u; }

    UART_SendString((const u8 *)"[3] Read back       ... ");
    if (pass)
    {
        UART_SendString((const u8 *)"PASS");
        UART_SendNewLine();
        UART_SendString((const u8 *)"    Seconds = "); UART_Send2Digits(secs); UART_SendNewLine();
        UART_SendString((const u8 *)"    Minutes = "); UART_Send2Digits(mins); UART_SendNewLine();
        UART_SendString((const u8 *)"    Hours   = "); UART_Send2Digits(hrs);  UART_SendNewLine();
    }
    else
    {
        UART_SendString((const u8 *)"FAIL (values mismatch or NACK)");
        UART_SendNewLine();
    }

    return pass;
}


/* ════════════════════════════════════════
   MAIN
   ════════════════════════════════════════ */
void main(void)
{
    unsigned char passCount = 0u;
    unsigned char err       = 0u;
    unsigned char secs, mins, hrs;

    I2C_Init();
    UART_Init();

    Delay_ms(200u);   /* let DS1307 power up */

    UART_SendString((const u8 *)"=== I2C Driver Test ===");
    UART_SendNewLine();
    UART_SendString((const u8 *)"Target: DS1307 RTC @ 0x68");
    UART_SendNewLine();
    UART_SendNewLine();

    passCount += Test_Presence();
    Delay_ms(10u);
    passCount += Test_Write();
    Delay_ms(10u);
    passCount += Test_Read();

    UART_SendNewLine();
    UART_SendNumber((u32)passCount);
    UART_SendString((const u8 *)"/3 tests PASSED");
    UART_SendNewLine();

    if (passCount == 3u)
        UART_SendString((const u8 *)">> I2C driver OK");
    else
        UART_SendString((const u8 *)">> CHECK wiring / pull-ups");

    UART_SendNewLine();
    UART_SendNewLine();

    /* ── Live clock readout every second ── */
    UART_SendString((const u8 *)"-- Live clock --");
    UART_SendNewLine();

    while (1)
    {
        secs = FROM_BCD(I2C_ReadRegister(DS1307_ADDR, 0x00u, &err) & 0x7Fu);
        mins = FROM_BCD(I2C_ReadRegister(DS1307_ADDR, 0x01u, &err));
        hrs  = FROM_BCD(I2C_ReadRegister(DS1307_ADDR, 0x02u, &err) & 0x3Fu);

        UART_SendString((const u8 *)"Time: ");
        UART_Send2Digits(hrs);
        UART_SendByte(':');
        UART_Send2Digits(mins);
        UART_SendByte(':');
        UART_Send2Digits(secs);
        UART_SendNewLine();

        Delay_ms(1000u);
    }
}
