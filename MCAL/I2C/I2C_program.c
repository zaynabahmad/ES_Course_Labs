#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


/* ── Internal helper: wait until the MSSP is idle ──────────────────
 * Checks both the SSPIF flag (transfer complete) and the active
 * condition bits in SSPCON2 (SEN/RSEN/PEN/RCEN/ACKEN).
 * Must be called after every bus operation.                        */
static void I2C_WaitIdle(void)
{
    /* Wait for any start/stop/receive/ack sequence to finish */
    while (
        GET_BIT(I2C_SSPCON2, I2C_SSPCON2_SEN)   ||
        GET_BIT(I2C_SSPCON2, I2C_SSPCON2_RSEN)  ||
        GET_BIT(I2C_SSPCON2, I2C_SSPCON2_PEN)   ||
        GET_BIT(I2C_SSPCON2, I2C_SSPCON2_RCEN)  ||
        GET_BIT(I2C_SSPCON2, I2C_SSPCON2_ACKEN) ||
        GET_BIT(I2C_SSPSTAT, I2C_SSPSTAT_R_W)
    ) { }

    /* Clear the SSP interrupt flag */
    CLR_BIT(I2C_PIR1, I2C_PIR1_SSPIF);
}


/* ════════════════════════════════════════
   INIT
   ════════════════════════════════════════ */
void I2C_Init(void)
{
    /* ── Step 1: SCL (RC3) and SDA (RC4) must be inputs.
     * The MSSP open-drain hardware drives them low when needed;
     * pull-ups on the board pull them high when released.        */
    SET_BIT(I2C_TRISC, I2C_TRISC3);
    SET_BIT(I2C_TRISC, I2C_TRISC4);

    /* ── Step 2: Baud rate ── */
    I2C_SSPADD = I2C_SSPADD_VALUE;   /* 100 kHz @ 8 MHz = 19 */

    /* ── Step 3: SSPSTAT – disable slew rate control for 100 kHz ── */
    I2C_SSPSTAT = 0x80;   /* SMP=1 (slew off for 100k), rest 0 */

    /* ── Step 4: SSPCON – I2C Master mode, enable module ── */
    I2C_SSPCON  = 0x00;
    I2C_SSPCON |= I2C_MASTER_MODE;           /* SSPM[3:0] = 1000 */
    SET_BIT(I2C_SSPCON, I2C_SSPCON_SSPEN);  /* Enable MSSP       */

    /* ── Step 5: SSPCON2 – clear all condition bits ── */
    I2C_SSPCON2 = 0x00;
}


/* ════════════════════════════════════════
   BUS CONDITIONS
   ════════════════════════════════════════ */

void I2C_Start(void)
{
    I2C_WaitIdle();
    SET_BIT(I2C_SSPCON2, I2C_SSPCON2_SEN);  /* Initiate Start */
    I2C_WaitIdle();                           /* Wait for it to complete */
}

void I2C_RepeatedStart(void)
{
    I2C_WaitIdle();
    SET_BIT(I2C_SSPCON2, I2C_SSPCON2_RSEN); /* Initiate Repeated Start */
    I2C_WaitIdle();
}

void I2C_Stop(void)
{
    I2C_WaitIdle();
    SET_BIT(I2C_SSPCON2, I2C_SSPCON2_PEN);  /* Initiate Stop */
    I2C_WaitIdle();
}


/* ════════════════════════════════════════
   SEND / RECEIVE
   ════════════════════════════════════════ */

/* Loads byte into SSPBUF, waits for transmission, returns ACKSTAT.
 * ACKSTAT = 0 → slave sent ACK  (success)
 * ACKSTAT = 1 → slave sent NACK (error / not present)            */
unsigned char I2C_SendByte(unsigned char val)
{
    I2C_WaitIdle();
    I2C_SSPBUF = val;              /* Writing starts the transmission */
    I2C_WaitIdle();                /* Wait until byte + ACK are done  */
    return GET_BIT(I2C_SSPCON2, I2C_SSPCON2_ACKSTAT);
}

/* Enables receive mode, waits for byte, sends ACK or NACK.       */
unsigned char I2C_ReceiveByte(unsigned char sendACK)
{
    unsigned char val;

    I2C_WaitIdle();

    /* Enable receive mode – master clocks in one byte */
    SET_BIT(I2C_SSPCON2, I2C_SSPCON2_RCEN);
    I2C_WaitIdle();                /* Wait until byte is in SSPBUF   */

    val = I2C_SSPBUF;             /* Read received byte             */

    /* Send ACK or NACK */
    if (sendACK == 1u)
        CLR_BIT(I2C_SSPCON2, I2C_SSPCON2_ACKDT);   /* ACKDT=0 → ACK  */
    else
        SET_BIT(I2C_SSPCON2, I2C_SSPCON2_ACKDT);   /* ACKDT=1 → NACK */

    SET_BIT(I2C_SSPCON2, I2C_SSPCON2_ACKEN);       /* Send the ACK/NACK */
    I2C_WaitIdle();

    return val;
}


/* ════════════════════════════════════════
   HIGH-LEVEL HELPERS
   ════════════════════════════════════════ */

/*
 * I2C_MasterWrite
 * START → (slaveAddr << 1 | WRITE) → reg/data bytes → STOP
 */
unsigned char I2C_MasterWrite(unsigned char slaveAddr,
                               unsigned char *val,
                               unsigned char len)
{
    unsigned char i;
    unsigned char nack;

    I2C_Start();

    /* Send address with W bit (bit0 = 0) */
    nack = I2C_SendByte((unsigned char)((slaveAddr << 1u) & 0xFEu));
    if (nack) { I2C_Stop(); return 1u; }

    for (i = 0u; i < len; i++)
    {
        nack = I2C_SendByte(val[i]);
        if (nack) { I2C_Stop(); return 1u; }
    }

    I2C_Stop();
    return 0u;
}

/*
 * I2C_MasterRead
 * START → (slaveAddr << 1 | READ) → receive bytes → STOP
 */
unsigned char I2C_MasterRead(unsigned char slaveAddr,
                              unsigned char *buf,
                              unsigned char len)
{
    unsigned char i;
    unsigned char nack;

    I2C_Start();

    /* Send address with R bit (bit0 = 1) */
    nack = I2C_SendByte((unsigned char)((slaveAddr << 1u) | 0x01u));
    if (nack) { I2C_Stop(); return 1u; }

    for (i = 0u; i < len; i++)
    {
        /* ACK all bytes except the last one */
        if (i < (len - 1u))
            buf[i] = I2C_ReceiveByte(1u);   /* ACK  */
        else
            buf[i] = I2C_ReceiveByte(0u);   /* NACK – signals last byte */
    }

    I2C_Stop();
    return 0u;
}

/*
 * I2C_WriteRegister
 * START → addr+W → regAddr → value → STOP
 */
unsigned char I2C_WriteRegister(unsigned char slaveAddr,
                                 unsigned char regAddr,
                                 unsigned char value)
{
    unsigned char buf[2];
    buf[0] = regAddr;
    buf[1] = value;
    return I2C_MasterWrite(slaveAddr, buf, 2u);
}

/*
 * I2C_ReadRegister
 * START → addr+W → regAddr → REPEATED START → addr+R → read byte → STOP
 */
unsigned char I2C_ReadRegister(unsigned char slaveAddr,
                                unsigned char regAddr,
                                unsigned char *error)
{
    unsigned char nack;
    unsigned char val;

    I2C_Start();

    /* Phase 1: write register address */
    nack = I2C_SendByte((unsigned char)((slaveAddr << 1u) & 0xFEu));
    if (nack) { I2C_Stop(); *error = 1u; return 0u; }

    nack = I2C_SendByte(regAddr);
    if (nack) { I2C_Stop(); *error = 1u; return 0u; }

    /* Phase 2: repeated start then read */
    I2C_RepeatedStart();

    nack = I2C_SendByte((unsigned char)((slaveAddr << 1u) | 0x01u));
    if (nack) { I2C_Stop(); *error = 1u; return 0u; }

    val = I2C_ReceiveByte(0u);   /* NACK on last (only) byte */

    I2C_Stop();
    *error = 0u;
    return val;
}