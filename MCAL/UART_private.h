/**
 * @file    UART_private.h
 * @brief   Register map and timing constants for the USART driver.
 *
 * @details The USART status, control and data registers live in different
 *          banks; gathering their addresses here lets UART.c read as plain
 *          logic. Fosc is kept as a constant because the baud-rate solver
 *          needs it in integer form.
 */
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../SERVICES/Types.h"

#define UART_REG_TXSTA      ( *((volatile byte_t *)0x98u) )
#define UART_REG_RCSTA      ( *((volatile byte_t *)0x18u) )
#define UART_REG_SPBRG      ( *((volatile byte_t *)0x99u) )
#define UART_REG_TXREG      ( *((volatile byte_t *)0x19u) )
#define UART_REG_RCREG      ( *((volatile byte_t *)0x1Au) )
#define UART_REG_PIR1       ( *((volatile byte_t *)0x0Cu) )
#define UART_REG_TRISC      ( *((volatile byte_t *)0x87u) )

/* TXSTA bits. */
#define UART_BIT_TXEN       5u          /* transmit enable                  */
#define UART_BIT_SYNC       4u          /* 0 = asynchronous mode            */
#define UART_BIT_BRGH       2u          /* 1 = high-speed baud generator    */

/* RCSTA bits. */
#define UART_BIT_SPEN       7u          /* serial port enable               */
#define UART_BIT_CREN       4u          /* continuous receive enable        */
#define UART_BIT_OERR       1u          /* receive overrun error            */

/* PIR1 bits. */
#define UART_BIT_TXIF       4u          /* transmit register empty          */
#define UART_BIT_RCIF       5u          /* receive register full            */

/* TX = RC6, RX = RC7. */
#define UART_PIN_TX         6u
#define UART_PIN_RX         7u

/* Core clock used by the baud-rate solver. */
#define UART_FOSC_HZ        20000000uL

/* Largest value that fits the 8-bit SPBRG register. */
#define UART_SPBRG_MAX      255uL

#endif /* UART_PRIVATE_H */
