#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* --- Register Definitions --- */
#define SSPCON   (*((volatile u8 *)0x14))
#define SSPCON2  (*((volatile u8 *)0x91))
#define SSPSTAT  (*((volatile u8 *)0x94))
#define SSPADD   (*((volatile u8 *)0x93))
#define SSPBUF   (*((volatile u8 *)0x13))

/* --- SSPSTAT Bits --- */
#define R_W_BIT      2  /* Read/Write Information bit */

/* --- SSPCON Bits --- */
#define SSPM0_BIT    0  /* MSSP Mode Select bits */
#define SSPM1_BIT    1
#define SSPM2_BIT    2
#define SSPM3_BIT    3
#define SSPEN_BIT    5  /* Synchronous Serial Port Enable bit */

/* --- SSPSTAT Bits --- */
#define SMP_BIT      7  /* Slew Rate Control bit */
#define R_W_BIT      2  

/* --- SSPCON2 Bits --- */
#define SEN_BIT      0  /* Start Condition Enable bit */
#define RSEN_BIT     1  /* Repeated Start Condition Enable bit */
#define PEN_BIT      2  /* Stop Condition Enable bit */
#define RCEN_BIT     3  /* Receive Enable bit */
#define ACKEN_BIT    4  /* Acknowledge Sequence Enable bit */
#define ACKDT_BIT    5  /* Acknowledge Data bit */
#define ACKSTAT_BIT  6  /* Acknowledge Status bit (1=NACK, 0=ACK) */

#endif