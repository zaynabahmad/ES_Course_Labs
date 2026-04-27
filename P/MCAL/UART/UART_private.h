#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* ---- UART registers (mikroC SFR names) ---- */
#define TXREG_REG   TXREG
#define RCREG_REG   RCREG
#define TXSTA_REG   TXSTA
#define RCSTA_REG   RCSTA
#define SPBRG_REG   SPBRG
#define PIR1_REG    PIR1

/* ---- Bit positions ---- */
#define TXIF_BIT    4   /* Transmit buffer empty flag */
#define RCIF_BIT    5   /* Receive buffer full flag   */
#define TXEN_BIT    5   /* Transmit enable            */
#define BRGH_BIT    2   /* High baud rate select      */
#define SPEN_BIT    7   /* Serial port enable         */
#define CREN_BIT    4   /* Continuous receive enable  */

#endif
