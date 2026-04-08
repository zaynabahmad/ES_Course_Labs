#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "I2C_Private.h"
#include "I2C_Config.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

/* -------------------------------------------------------
 * Initialization
 * Call I2C_Master_Init() or I2C_Slave_Init() once at
 * startup according to the role of this node.
 * ------------------------------------------------------- */
void I2C_Master_Init(void);
void I2C_Slave_Init(void);

/* -------------------------------------------------------
 * Bus Conditions  (Master only)
 *
 * I2C_Start   — assert a Start  condition (S).
 * I2C_Stop    — assert a Stop   condition (P).
 * I2C_Restart — assert a Repeated Start  (Sr) without
 *               releasing the bus between transactions.
 * ------------------------------------------------------- */
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);

/* -------------------------------------------------------
 * Data Transfer
 *
 * I2C_Write — transmit one byte (address or data).
 *             Returns 0 if the slave ACK'd, 1 on NACK.
 *
 * I2C_Read  — clock in one byte from the slave.
 *             Follow with I2C_ACK() if more bytes are
 *             expected, or I2C_NACK() on the last byte.
 * ------------------------------------------------------- */
u8 I2C_Write(u8 Data);
u8 I2C_Read(void);

/* -------------------------------------------------------
 * Acknowledge Control  (Master Receiver mode)
 *
 * I2C_ACK  — send ACK  after receiving a byte to request
 *             the next byte from the slave transmitter.
 * I2C_NACK — send NACK after receiving the final byte to
 *             signal the slave to release the bus.
 * ------------------------------------------------------- */
void I2C_ACK(void);
void I2C_NACK(void);

/* -------------------------------------------------------
 * Interrupt-Driven Support
 * Register a callback; it is called from I2C_ISR() with
 * the byte just received from SSPBUF.  Call I2C_ISR()
 * from the global ISR when SSPIF is detected.
 * ------------------------------------------------------- */
void I2C_SetCallback(void (*Callback)(u8));
void I2C_ISR(void);

#endif
