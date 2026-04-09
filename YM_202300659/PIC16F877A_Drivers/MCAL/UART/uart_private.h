/*
 * uart_private.h
 * MCAL - UART (USART) Register Definitions for PIC16F877A
 */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* =====================================================
 * USART Registers
 * ===================================================== */

/* TXREG - Transmit Register (Bank 0) */
#define TXREG_REG      (*((volatile unsigned char*)0x19))

/* RCREG - Receive Register (Bank 0) */
#define RCREG_REG      (*((volatile unsigned char*)0x1A))

/* SPBRG - Baud Rate Generator (Bank 1) */
#define SPBRG_REG      (*((volatile unsigned char*)0x99))

/* TXSTA - Transmit Status and Control (Bank 1) */
#define TXSTA_REG      (*((volatile unsigned char*)0x98))

/* RCSTA - Receive Status and Control (Bank 0) */
#define RCSTA_REG      (*((volatile unsigned char*)0x18))

/* =====================================================
 * TXSTA Bit Positions
 * ===================================================== */
#define TXSTA_CSRC    7    /* Clock Source Select     */
#define TXSTA_TX9     6    /* 9-bit Transmit Enable   */
#define TXSTA_TXEN    5    /* Transmit Enable         */
#define TXSTA_SYNC    4    /* SYNC mode: 0=async      */
#define TXSTA_BRGH    2    /* High Baud Rate Select   */
#define TXSTA_TRMT    1    /* Transmit Shift Reg Empty*/
#define TXSTA_TX9D    0    /* 9th bit of Transmit data*/

/* =====================================================
 * RCSTA Bit Positions
 * ===================================================== */
#define RCSTA_SPEN    7    /* Serial Port Enable      */
#define RCSTA_RX9     6    /* 9-bit Receive Enable    */
#define RCSTA_SREN    5    /* Single Receive Enable   */
#define RCSTA_CREN    4    /* Continuous Receive Enable*/
#define RCSTA_ADDEN   3    /* Address Detect Enable   */
#define RCSTA_FERR    2    /* Framing Error           */
#define RCSTA_OERR    1    /* Overrun Error           */
#define RCSTA_RX9D    0    /* 9th bit of received data*/

/* PIR1 for interrupt flags */
#define PIR1_REG      (*((volatile unsigned char*)0x0C))
#define PIR1_TXIF     4    /* USART Transmit Interrupt Flag */
#define PIR1_RCIF     5    /* USART Receive Interrupt Flag  */

/* TRISC for TX/RX pins */
#define TRISC_REG     (*((volatile unsigned char*)0x87))

#endif /* UART_PRIVATE_H */
