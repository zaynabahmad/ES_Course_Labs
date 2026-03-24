#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ── MSSP Registers ── */
#define SSPBUF      (*(volatile u8*)0x13)   /* SSP Receive/Transmit Buffer   */
#define SSPCON      (*(volatile u8*)0x14)   /* SSP Control Register          */
#define SSPCON2     (*(volatile u8*)0x91)   /* SSP Control Register 2        */
#define SSPSTAT     (*(volatile u8*)0x94)   /* SSP Status Register           */
#define SSPADD      (*(volatile u8*)0x93)   /* SSP Address / Baud Rate       */

/* ── SSPCON bits ── */
#define SSPCON_SSPEN    5   /* SSP Enable                    */
#define SSPCON_WCOL     7   /* Write Collision Detect        */
#define SSPCON_SSPOV    6   /* Receive Overflow Indicator    */

/* ── SSPCON2 bits ── */
#define SSPCON2_SEN     0   /* Start Condition Enable        */
#define SSPCON2_RSEN    1   /* Repeated Start Enable         */
#define SSPCON2_PEN     2   /* Stop Condition Enable         */
#define SSPCON2_RCEN    3   /* Receive Enable                */
#define SSPCON2_ACKEN   4   /* Acknowledge Sequence Enable   */
#define SSPCON2_ACKDT   5   /* Acknowledge Data bit (0=ACK)  */
#define SSPCON2_ACKSTAT 6   /* Acknowledge Status            */

/* ── SSPSTAT bits ── */
#define SSPSTAT_BF      0   /* Buffer Full                   */
#define SSPSTAT_R_W     2   /* Read/Write (slave mode)       */
#define SSPSTAT_SMP     7   /* Slew Rate Control (1=disable) */
#define SSPSTAT_CKE     6   /* SMBus Select                  */

/* ── TRISC for I2C pins ── */
#define TRISC       (*(volatile u8*)0x87)
#define TRISC3      3       /* SCL → RC3 must be input       */
#define TRISC4      4       /* SDA → RC4 must be input       */

#endif
