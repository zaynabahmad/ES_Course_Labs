/**
 * @file    app_i2c.c
 * @brief   I2C master application -- application layer, no register access.
 *
 * @details A canonical "write one register" transaction: START, the slave
 *          address with its write bit, a register index, a data byte, STOP.
 *          The application composes the transaction; the MCAL only knows how
 *          to push a single byte and read an acknowledge.
 */
#include "app_i2c.h"
#include "../MCAL/I2C_interface.h"
#include "../MCAL/UART_interface.h"

/* 7-bit slave address 0x50 shifted up, write bit (0) appended -> 0xA0. */
#define APP_I2C_SLAVE_WRITE     0xA0u
/** Register index written inside the slave. */
#define APP_I2C_REG_INDEX       0x10u
/** Value placed in that register. */
#define APP_I2C_REG_VALUE       0x2Au
/** Pause between transactions, in milliseconds. */
#define APP_I2C_PERIOD_MS       1000u

/**
 * @brief  Report the outcome of one byte over the UART.
 */
static void vReport(const char *pcLabel, eOutcome_t eResult)
{
    vUART_SendString(pcLabel);
    vUART_SendString((eResult == OUTCOME_OK) ? " ACK\r\n" : " NACK\r\n");
}

void vApp_I2c(void)
{
    vI2C_MasterInit();
    vUART_Init();

    while (1)
    {
        vI2C_Start();
        vReport("addr", u8I2C_Write(APP_I2C_SLAVE_WRITE));
        vReport("reg",  u8I2C_Write(APP_I2C_REG_INDEX));
        vReport("data", u8I2C_Write(APP_I2C_REG_VALUE));
        vI2C_Stop();

        Delay_ms(APP_I2C_PERIOD_MS);
    }
}
