#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

/* ================= Register Addresses ================= */

#define SSPCON       (*((volatile u8*)0x14))
#define SSPCON2      (*((volatile u8*)0x91))
#define SSPSTAT      (*((volatile u8*)0x94))
#define SSPBUF       (*((volatile u8*)0x13))
#define SSPADD       (*((volatile u8*)0x93))
#define PIR1         (*((volatile u8*)0x0C))
#define PIR2         (*((volatile u8*)0x0D))
#define PIE2         (*((volatile u8*)0x8D))
#define INTCON       (*((volatile u8*)0x0B))
#define TRISC        (*((volatile u8*)0x87))

/* ================= SSPCON Bits ================= */

#define SSPM0        0
#define SSPM1        1
#define SSPM2        2
#define SSPM3        3
#define CKP          4      /* Release SCL clock (slave) */
#define SSPEN        5      /* SSP Enable */
#define SSPOV        6      /* Receive Overflow */
#define WCOL         7      /* Write Collision */

/* ================= SSPCON2 Bits ================= */

#define SEN          0      /* Start Condition Enable */
#define RSEN         1      /* Repeated Start Condition Enable */
#define PEN          2      /* Stop Condition Enable */
#define RCEN         3      /* Receive Enable */
#define ACKEN        4      /* Acknowledge Sequence Enable */
#define ACKDT        5      /* Acknowledge Data bit: 0=ACK, 1=NACK */
#define ACKSTAT      6      /* Acknowledge Status bit */
#define GCEN         7      /* General Call Enable */

/* ================= SSPSTAT Bits ================= */

#define BF           0      /* Buffer Full */
#define UA           1      /* Update Address */
#define R_W          2      /* Read/Write info */
#define S_BIT        3      /* Start Bit */
#define P_BIT        4      /* Stop Bit */
#define D_A          5      /* Data/Address */
#define CKE          6      /* Clock Edge */
#define SMP          7      /* Slew Rate Control */

/* ================= PIR1 Bits ================= */

#define SSPIF        3

/* ================= INTCON Bits ================= */

#define GIE_BIT      7
#define PEIE_BIT     6

#endif
