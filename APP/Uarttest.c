

#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../SERVICES/STD_TYPES.h"

/* ── Simple blocking delay (approx. ms @ 8 MHz, no Timer needed) ── */
static void Delay_ms(u16 ms)
{
    u16 i, j;
    for (i = 0u; i < ms; i++)
        for (j = 0u; j < 200u; j++) { }   /* ~200 loops ≈ 1 ms @ 8 MHz */
}

/* ── Main ─────────────────────────────────────────────────────────── */
int main(void)
{
    u16 Local_ADC_Raw;
    u32 Local_mV;
    u32 Local_Temp;

    /* Initialise peripherals */
    ADC_Init();
    UART_Init();

    /* Startup message */
    UART_SendString((const u8 *)"=== ADC + UART Test ===");
    UART_SendNewLine();
    UART_SendString((const u8 *)"LM35 on AN0, 8 MHz, 9600 baud");
    UART_SendNewLine();
    UART_SendNewLine();

    while (1)
    {
        /* ── 1. Read ADC (10-bit, Vref = 5 V) ───────────────────── */
        Local_ADC_Raw = ADC_Read(0u);   /* channel 0 = RA0 */

        /* ── 2. Convert to millivolts  (5000 mV / 1024 steps) ───── */
        Local_mV = ((u32)Local_ADC_Raw * 5000uL) / 1024uL;

        /* ── 3. LM35: 10 mV per °C → Temp = mV / 10 ────────────── */
        Local_Temp = Local_mV / 10uL;

        /* ── 4. Send over UART ───────────────────────────────────── */
        UART_SendString((const u8 *)"ADC=");
        UART_SendNumber((u32)Local_ADC_Raw);

        UART_SendString((const u8 *)"  mV=");
        UART_SendNumber(Local_mV);

        UART_SendString((const u8 *)"  T=");
        UART_SendNumber(Local_Temp);
        UART_SendString((const u8 *)" C");

        UART_SendNewLine();

        Delay_ms(500u);
    }
    return 0;
}