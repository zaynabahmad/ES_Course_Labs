#include "SPI_Interface.h"


/* =================================
   Global Pointer To Callback
================================= */

void (*SPI_Callback)(u8) = 0;


/* =================================
   Master Initialization
================================= */

void SPI_Master_Init(void)
{
    /* --- Step 1: Clear SSPM<3:0>, then set clock-rate bits --- */
    CLR_BIT(SSPCON, SSPM0);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);

#if   SPI_SELECTED_MODE == SPI_MASTER_FOSC16
    SET_BIT(SSPCON, SSPM0);                     /* 0001 */
#elif SPI_SELECTED_MODE == SPI_MASTER_FOSC64
    SET_BIT(SSPCON, SSPM1);                     /* 0010 */
#elif SPI_SELECTED_MODE == SPI_MASTER_TMR2
    SET_BIT(SSPCON, SSPM0);
    SET_BIT(SSPCON, SSPM1);                     /* 0011 */
#endif
    /* SPI_MASTER_FOSC4 → 0000 → nothing extra to set */

    /* --- Step 2: Clock Polarity (CKP) --- */
#if SPI_CKP_VALUE == 1
    SET_BIT(SSPCON, CKP_BIT);                   /* Idle HIGH */
#else
    CLR_BIT(SSPCON, CKP_BIT);                   /* Idle LOW  */
#endif

    /* --- Step 3: Clock Phase / Edge (CKE in SSPSTAT) --- */
#if SPI_CKE_VALUE == 1
    SET_BIT(SSPSTAT, CKE_BIT);                  /* Transmit on leading  edge */
#else
    CLR_BIT(SSPSTAT, CKE_BIT);                  /* Transmit on trailing edge */
#endif

    /* --- Step 4: Input Sample Phase (SMP in SSPSTAT) --- */
#if SPI_SMP_VALUE == 1
    SET_BIT(SSPSTAT, SMP_BIT);                  /* Sample at end    of output */
#else
    CLR_BIT(SSPSTAT, SMP_BIT);                  /* Sample at middle of output */
#endif

    /* --- Step 5: IO pin directions for Master mode --- */
    CLR_BIT(TRISC, RC5);    /* SDO → Output                          */
    SET_BIT(TRISC, RC4);    /* SDI → Input  (also controlled by MSSP) */
    CLR_BIT(TRISC, RC3);    /* SCK → Output (master drives the clock) */

    /* --- Step 6: Enable the MSSP peripheral --- */
    SET_BIT(SSPCON, SSPEN);

    /* --- Step 7: Optional interrupt-driven mode --- */
#if SPI_INTERRUPT_EN == 1
    SET_BIT(PIE1,   SSPIE);
    SET_BIT(INTCON, PEIE);
    SET_BIT(INTCON, GIE);
#endif
}


/* =================================
   Slave Initialization
================================= */

void SPI_Slave_Init(void)
{
    /* --- Step 1: Set SSPM<3:0> for Slave mode --- */
    CLR_BIT(SSPCON, SSPM0);
    CLR_BIT(SSPCON, SSPM1);
    CLR_BIT(SSPCON, SSPM2);
    CLR_BIT(SSPCON, SSPM3);

#if SPI_SELECTED_MODE == SPI_SLAVE_SS_DIS
    SET_BIT(SSPCON, SSPM2);
    SET_BIT(SSPCON, SSPM0);                     /* 0101 – SS disabled */
#else
    SET_BIT(SSPCON, SSPM2);                     /* 0100 – SS enabled  */
#endif

    /* --- Step 2: Clock Polarity (CKP) — must match the master --- */
#if SPI_CKP_VALUE == 1
    SET_BIT(SSPCON, CKP_BIT);
#else
    CLR_BIT(SSPCON, CKP_BIT);
#endif

    /* --- Step 3: Clock Phase (CKE) — must match the master --- */
#if SPI_CKE_VALUE == 1
    SET_BIT(SSPSTAT, CKE_BIT);
#else
    CLR_BIT(SSPSTAT, CKE_BIT);
#endif

    /* --- Step 4: SMP must be cleared in Slave mode (datasheet req.) --- */
    CLR_BIT(SSPSTAT, SMP_BIT);

    /* --- Step 5: IO pin directions for Slave mode --- */
    CLR_BIT(TRISC, RC5);    /* SDO → Output                              */
    SET_BIT(TRISC, RC4);    /* SDI → Input                               */
    SET_BIT(TRISC, RC3);    /* SCK → Input (slave receives clock)        */

#if SPI_SELECTED_MODE == SPI_SLAVE_SS_EN
    /* Make RA5/AN4 a digital input for the SS line.
       ADCON1<3:0> = 0b0110 keeps RA5 as digital I/O.           */
    CLR_BIT(ADCON1, 0);
    SET_BIT(ADCON1, 1);
    SET_BIT(ADCON1, 2);
    CLR_BIT(ADCON1, 3);
    SET_BIT(TRISA, RA5);    /* SS → Input                                */
#endif

    /* --- Step 6: Enable the MSSP peripheral --- */
    SET_BIT(SSPCON, SSPEN);

    /* --- Step 7: Interrupts (highly recommended in Slave mode) --- */
#if SPI_INTERRUPT_EN == 1
    SET_BIT(PIE1,   SSPIE);
    SET_BIT(INTCON, PEIE);
    SET_BIT(INTCON, GIE);
#endif
}


/* =================================
   Send Byte (Blocking Transmit)
================================= */

void SPI_Write(u8 Data)
{
    SSPBUF = Data;                          /* Load data → starts shift-out  */

    while (!GET_BIT(SSPSTAT, BF));          /* Wait: BF set when byte is done */

    (void)SSPBUF;                           /* Dummy read to clear the BF flag */
}


/* =================================
   Receive Byte (Polling)
================================= */

u8 SPI_Read(void)
{
    SSPBUF = 0xFF;                          /* Dummy write to generate SCK     */

    while (!GET_BIT(SSPSTAT, BF));          /* Wait until reception complete   */

    return SSPBUF;                          /* Reading SSPBUF clears BF        */
}


/* =================================
   Full-Duplex Transfer
   Sends Data and simultaneously
   returns the byte clocked in.
================================= */

u8 SPI_Transfer(u8 Data)
{
    SSPBUF = Data;                          /* Load outgoing byte             */

    while (!GET_BIT(SSPSTAT, BF));          /* Wait for transfer to finish    */

    return SSPBUF;                          /* Return the simultaneously recv'd byte */
}


/* =================================
   TX Done Status
================================= */

u8 SPI_TX_Done(void)
{
    return GET_BIT(SSPSTAT, BF);
}


/* =================================
   Callback Setter
================================= */

void SPI_SetCallback(void (*Callback)(u8))
{
    if (Callback != 0)
    {
        SPI_Callback = Callback;
    }
}


/* =================================
   ISR Handler
   Call this from the global ISR when
   SSPIF is detected.
================================= */

void SPI_ISR(void)
{
    u8 SPI_Data = SSPBUF;               /* Read clears BF; must be done in ISR */

    if (SPI_Callback != 0)
    {
        SPI_Callback(SPI_Data);
    }
}


/* =================================
   Global ISR Entry Point (template)

void interrupt()
{
    if (GET_BIT(PIR1, SSPIF))
    {
        SPI_ISR();
        CLR_BIT(PIR1, SSPIF);           // Clear flag after servicing
    }
}
================================= */
