/**
 * @file    uart.c
 * @brief   PIC16F877 UART Driver Implementation
 */

#include "uart.h"

/*------------------------------------------------------------
 * UART_Init
 *------------------------------------------------------------*/
void UART_Init(const UART_Config_t *cfg)
{
    uint16_t spbrg;

    /* Step 1: Set RC6 (TX) as output, RC7 (RX) as input */
    TRISCbits.TRISC6 = 0;  /* TX → output */
    TRISCbits.TRISC7 = 1;  /* RX → input  */

    /* Step 2: Compute baud rate register */
    if (cfg->brgh == UART_BRGH_HIGH) {
        spbrg = (uint16_t)((cfg->foscHz / (16u * cfg->baudRate)) - 1u);
    } else {
        spbrg = (uint16_t)((cfg->foscHz / (64u * cfg->baudRate)) - 1u);
    }
    SPBRG = (uint8_t)spbrg;

    /* Step 3: Configure TXSTA
     *  SYNC=0 (async), BRGH=user, TXEN=1, TX9=user
     */
    TXSTA = 0x00u;
    TXSTAbits.SYNC  = 0;
    TXSTAbits.BRGH  = (uint8_t)cfg->brgh;
    TXSTAbits.TX9   = (uint8_t)cfg->dataBits;
    TXSTAbits.TXEN  = 1;

    /* Step 4: Configure RCSTA — enable serial port and continuous receive */
    RCSTA = 0x00u;
    RCSTAbits.SPEN  = 1;
    RCSTAbits.CREN  = 1;
    RCSTAbits.RX9   = (uint8_t)cfg->dataBits;

    /* Step 5: Interrupt configuration (needs PEIE + GIE set externally) */
    PIR1bits.TXIF = 0;
    PIR1bits.RCIF = 0;

    PIE1bits.TXIE = (uint8_t)cfg->txIntEn;
    PIE1bits.RCIE = (uint8_t)cfg->rxIntEn;
}

/*------------------------------------------------------------
 * UART_SendByte  — blocks until shift register is empty
 *------------------------------------------------------------*/
void UART_SendByte(uint8_t data)
{
    while (!TXSTAbits.TRMT) {
        /* Wait for TSR to be empty */
    }
    TXREG = data;
}

/*------------------------------------------------------------
 * UART_SendString
 *------------------------------------------------------------*/
void UART_SendString(const char *str)
{
    while (*str != '\0') {
        UART_SendByte((uint8_t)*str);
        str++;
    }
}

/*------------------------------------------------------------
 * UART_SendBuffer
 *------------------------------------------------------------*/
void UART_SendBuffer(const uint8_t *buf, uint8_t len)
{
    uint8_t i;
    for (i = 0u; i < len; i++) {
        UART_SendByte(buf[i]);
    }
}

/*------------------------------------------------------------
 * UART_ReceiveByte — blocks until data arrives
 *------------------------------------------------------------*/
uint8_t UART_ReceiveByte(void)
{
    while (!PIR1bits.RCIF) {
        /* Wait for data */
    }
    return RCREG;
}

/*------------------------------------------------------------
 * UART_DataAvailable
 *------------------------------------------------------------*/
uint8_t UART_DataAvailable(void)
{
    return (uint8_t)PIR1bits.RCIF;
}

/*------------------------------------------------------------
 * UART_GetError
 *------------------------------------------------------------*/
uint8_t UART_GetError(void)
{
    uint8_t err = UART_ERROR_NONE;
    if (RCSTAbits.OERR) err |= (uint8_t)UART_ERROR_OVERRUN;
    if (RCSTAbits.FERR) err |= (uint8_t)UART_ERROR_FRAMING;
    return err;
}

/*------------------------------------------------------------
 * UART_ClearOverrun
 * Must toggle CREN to clear OERR flag
 *------------------------------------------------------------*/
void UART_ClearOverrun(void)
{
    RCSTAbits.CREN = 0;
    RCSTAbits.CREN = 1;
}

/*------------------------------------------------------------
 * UART_Enable / Disable
 *------------------------------------------------------------*/
void UART_Enable(void)
{
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1;
    RCSTAbits.CREN = 1;
}

void UART_Disable(void)
{
    TXSTAbits.TXEN = 0;
    RCSTAbits.CREN = 0;
    RCSTAbits.SPEN = 0;
}

/*------------------------------------------------------------
 * Weak callbacks
 *------------------------------------------------------------*/
void __attribute__((weak)) UART_TX_Callback(void) { }
void __attribute__((weak)) UART_RX_Callback(void) { }

/*============================================================
 * ISR dispatch (standalone; merge with project ISR)
 *============================================================*/
#ifdef UART_USE_STANDALONE_ISR
void __interrupt() UART_ISR(void)
{
    if (PIE1bits.TXIE && PIR1bits.TXIF) {
        /* Flag clears automatically when TXREG is written */
        UART_TX_Callback();
    }
    if (PIE1bits.RCIE && PIR1bits.RCIF) {
        /* Flag clears when RCREG is read */
        UART_RX_Callback();
    }
}
#endif
