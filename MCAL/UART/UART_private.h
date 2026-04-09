#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* TXREG – Transmit Data Register       (Bank 0: 0x19) */
#define TXREG           (*(volatile u8*)0x19)

/* RCREG – Receive Data Register        (Bank 0: 0x1A) */
#define RCREG           (*(volatile u8*)0x1A)

/* TXSTA – Transmit Status & Control    (Bank 1: 0x98) */
#define TXSTA           (*(volatile u8*)0x98)
#define TXSTA_TXEN       5   /* Transmit Enable            */
#define TXSTA_SYNC       4   /* Sync mode (0 = async)      */
#define TXSTA_BRGH       2   /* High Baud Rate select      */
#define TXSTA_TRMT       1   /* Transmit Shift Reg Empty   */

/* RCSTA – Receive Status & Control     (Bank 0: 0x18) */
#define RCSTA           (*(volatile u8*)0x18)
#define RCSTA_SPEN       7   /* Serial Port Enable         */
#define RCSTA_CREN       4   /* Continuous Receive Enable  */
#define RCSTA_OERR       1   /* Overrun Error Flag         */
#define RCSTA_FERR       2   /* Framing Error Flag         */

/* SPBRG – Baud Rate Generator          (Bank 1: 0x99) */
#define SPBRG           (*(volatile u8*)0x99)

/* PIR1 – Peripheral Interrupt Flag     (Bank 0: 0x0C) */
#define PIR1            (*(volatile u8*)0x0C)
#define PIR1_TXIF        4   /* USART Transmit Interrupt Flag  */
#define PIR1_RCIF        5   /* USART Receive Interrupt Flag   */

/* TRISC – Port C direction             (Bank 1: 0x87) */
#define TRISC           (*(volatile u8*)0x87)
#define TRISC6           6   /* TX pin — must be output    */
#define TRISC7           7   /* RX pin — must be input     */

#define UART_SPBRG_9600      51u

#endif /* UART_PRIVATE_H */
