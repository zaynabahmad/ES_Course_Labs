#include "I2C_Interface.h"


/* =================================
   Global Pointer To Callback
================================= */

void (*I2C_Callback)(u8) = 0;


/* =================================
   Bus Idle Wait  (Internal Helper)

   Blocks until the previous I2C operation
   is complete and the bus is truly Idle.

   Two conditions must both be false:
     1. SSPSTAT<2> R_nW  — transmission in progress
     2. SSPCON2<4:0>     — SEN/RSEN/PEN/RCEN/ACKEN still active
================================= */

static void I2C_Wait(void)
{
    while ((SSPSTAT & I2C_SSPSTAT_BUSY_MASK) ||
           (SSPCON2 & I2C_SSPCON2_BUSY_MASK));
}


/* =================================
   Master Initialization
================================= */

void I2C_Master_Init(void)
{
    /* Step 1: SCL and SDA must be inputs — I2C uses open-drain drivers */
    SET_BIT(TRISC, RC3);    /* SCL → Input */
    SET_BIT(TRISC, RC4);    /* SDA → Input */

    /* Step 2: Baud Rate Generator
       SSPADD = (FOSC / (4 * BaudRate)) - 1                       */
    SSPADD = (u8)((FOSC / (4UL * I2C_BAUD_RATE)) - 1UL);

    /* Step 3: Clear control registers before configuring */
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;
    SSPCON1 = 0x00;

    /* Step 4: Select I2C Master mode (SSPM = 1000) and enable MSSP
       SSPCON1 = 0x28 → bit5 SSPEN=1, bit3 SSPM3=1 → 0b00101000  */
    SET_BIT(SSPCON1, SSPM3);    /* SSPM<3:0> = 1000 → I2C Master */
    SET_BIT(SSPCON1, SSPEN);    /* Enable MSSP                    */
}


/* =================================
   Slave Initialization
================================= */

void I2C_Slave_Init(void)
{
    /* Step 1: SCL and SDA must be inputs */
    SET_BIT(TRISC, RC3);    /* SCL → Input */
    SET_BIT(TRISC, RC4);    /* SDA → Input */

    /* Step 2: Write device address into SSPADD<7:1>
       The hardware compares SSPSR<7:1> against SSPADD<7:1>,
       so the 7-bit address is placed in the upper seven bits. */
    SSPADD = (u8)(I2C_SLAVE_ADDRESS << 1);

    /* Step 3: Disable Slew Rate Control for Standard-mode (100 kHz)
       SSPSTAT = 0x80 → SMP=1 (slew rate disabled)               */
    SSPSTAT = 0x80;

    /* Step 4: Select I2C Slave mode and enable MSSP */
    SSPCON1 = 0x00;

#if I2C_SLAVE_ADDR_MODE == I2C_SLAVE_7BIT
    SET_BIT(SSPCON1, SSPM2);
    SET_BIT(SSPCON1, SSPM1);    /* SSPM = 0110 → Slave 7-bit  */
#else
    SET_BIT(SSPCON1, SSPM2);
    SET_BIT(SSPCON1, SSPM1);
    SET_BIT(SSPCON1, SSPM0);    /* SSPM = 0111 → Slave 10-bit */
#endif

    SET_BIT(SSPCON1, SSPEN);    /* Enable MSSP */

    /* Step 5: Clock stretching
       SEN=1 holds SCL LOW after each receive so the ISR can read
       SSPBUF before the master sends the next byte.              */
#if I2C_CLOCK_STRETCH_EN == 1
    SET_BIT(SSPCON2, SEN);
#endif

    /* Step 6: Enable interrupts — mandatory for Slave mode operation */
    CLR_BIT(PIR1,   SSPIF);
    SET_BIT(PIE1,   SSPIE);
    SET_BIT(INTCON, PEIE);
    SET_BIT(INTCON, GIE);
}


/* =================================
   Generate Start Condition
================================= */

void I2C_Start(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, SEN);                  /* Initiate Start Condition       */
    while (GET_BIT(SSPCON2, SEN));          /* Hardware auto-clears SEN when done */
}


/* =================================
   Generate Stop Condition
================================= */

void I2C_Stop(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, PEN);                  /* Initiate Stop Condition        */
    while (GET_BIT(SSPCON2, PEN));          /* Hardware auto-clears PEN when done */
}


/* =================================
   Generate Repeated Start Condition
================================= */

void I2C_Restart(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, RSEN);                 /* Initiate Repeated Start        */
    while (GET_BIT(SSPCON2, RSEN));         /* Hardware auto-clears RSEN when done */
}


/* =================================
   Write Byte
   Returns 0 if slave ACK'd, 1 on NACK.
================================= */

u8 I2C_Write(u8 Data)
{
    I2C_Wait();
    SSPBUF = Data;                          /* Load byte → triggers transmission */
    I2C_Wait();
    return GET_BIT(SSPCON2, ACKSTAT);       /* 0 = ACK received, 1 = NACK        */
}


/* =================================
   Read Byte  (Master Receive Mode)
   Enable reception, wait for SSPIF,
   then return SSPBUF contents.
================================= */

u8 I2C_Read(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, RCEN);                 /* Enable & start reception       */

    while (!GET_BIT(PIR1, SSPIF));          /* Wait until byte received       */
    CLR_BIT(PIR1, SSPIF);                   /* Clear interrupt flag           */

    return SSPBUF;
}


/* =================================
   Send ACK  (Master Receiver Mode)
   Use after every byte except the last
   to request another byte from slave.
================================= */

void I2C_ACK(void)
{
    I2C_Wait();
    CLR_BIT(SSPCON2, ACKDT);               /* ACKDT = 0 → ACK                */
    SET_BIT(SSPCON2, ACKEN);               /* Initiate Acknowledge Sequence  */
    while (GET_BIT(SSPCON2, ACKEN));       /* Wait for hardware to complete  */
}


/* =================================
   Send NACK  (Master Receiver Mode)
   Use after the last byte to tell the
   slave transmitter to release the bus.
================================= */

void I2C_NACK(void)
{
    I2C_Wait();
    SET_BIT(SSPCON2, ACKDT);               /* ACKDT = 1 → NACK               */
    SET_BIT(SSPCON2, ACKEN);               /* Initiate Acknowledge Sequence  */
    while (GET_BIT(SSPCON2, ACKEN));       /* Wait for hardware to complete  */
}


/* =================================
   Callback Setter
================================= */

void I2C_SetCallback(void (*Callback)(u8))
{
    if (Callback != 0)
    {
        I2C_Callback = Callback;
    }
}


/* =================================
   ISR Handler
   Call this from the global ISR when
   SSPIF is detected.
================================= */

void I2C_ISR(void)
{
    u8 I2C_Data = SSPBUF;

    if (I2C_Callback != 0)
    {
        I2C_Callback(I2C_Data);
    }
}


/* =================================
   Global ISR Entry Point (template)

   --- Slave ISR skeleton ---

void interrupt()
{
    if (GET_BIT(PIR1, SSPIF))
    {
        CLR_BIT(SSPCON1, CKP);          // Stretch clock — hold SCL LOW

        if (GET_BIT(SSPCON1, SSPOV) || GET_BIT(SSPCON1, WCOL))
        {
            // Overflow or collision: flush buffer, clear flags
            volatile u8 Dummy = SSPBUF;
            CLR_BIT(SSPCON1, SSPOV);
            CLR_BIT(SSPCON1, WCOL);
        }
        else if (!GET_BIT(SSPSTAT, R_nW))   // Master is WRITING to us
        {
            volatile u8 Dummy = SSPBUF;     // Flush address byte if first byte
            while (!GET_BIT(SSPSTAT, BF));  // Wait for data byte
            I2C_ISR();                      // Read SSPBUF, invoke callback
        }
        else                                // Master is READING from us
        {
            volatile u8 Dummy = SSPBUF;     // Flush the address byte
            CLR_BIT(SSPSTAT, BF);
            SSPBUF = TX_Data;               // Load reply byte
        }

        SET_BIT(SSPCON1, CKP);          // Release SCL — resume clock
        CLR_BIT(PIR1, SSPIF);           // Clear interrupt flag
    }
}
================================= */
