#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ------- Registers ------- */
#define TRISC (*((volatile u8 *)0x87))
#define SSPBUF (*((volatile u8 *)0x13))
#define SSPCON (*((volatile u8 *)0x14))
#define SSPCON2 (*((volatile u8 *)0x91))
#define SSPSTAT (*((volatile u8 *)0x94))
#define SSPADD (*((volatile u8 *)0x93))
#define PIR1 (*((volatile u8 *)0x0C))

/* ------- SSPCON bits ------- */
#define SSPCON_SSPEN 5
#define SSPCON_SSPM3 3
#define SSPCON_SSPM2 2
#define SSPCON_SSPM1 1
#define SSPCON_SSPM0 0

/* ------- SSPCON2 bits ------- */
#define SSPCON2_SEN 0     /* Start condition enable  */
#define SSPCON2_RSEN 1    /* Repeated Start          */
#define SSPCON2_PEN 2     /* Stop condition enable   */
#define SSPCON2_RCEN 3    /* Receive enable          */
#define SSPCON2_ACKEN 4   /* ACK sequence enable     */
#define SSPCON2_ACKDT 5   /* ACK data (0=ACK,1=NACK) */
#define SSPCON2_ACKSTAT 6 /* ACK status (read only)  */

/* ------- SSPSTAT bits ------- */
#define SSPSTAT_BF 0  /* Buffer full             */
#define SSPSTAT_R_W 2 /* Read/Write              */

/* ------- PIR1 bits ------- */
#define PIR1_SSPIF 3 /* MSSP Interrupt Flag     */

#endif