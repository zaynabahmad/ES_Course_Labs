#ifndef I2C_TEST_H
#define I2C_TEST_H

#include "../../SERVICES/STD_TYPES.h"

/* Define Application Roles */
#define I2C_TEST_ROLE_MASTER    0
#define I2C_TEST_ROLE_SLAVE     1

/* Change this macro to switch between Master and Slave code */
#define I2C_TEST_ROLE           I2C_TEST_ROLE_MASTER

/* 
 * I2C Slave Addresses 
 * Note: These are shifted left by 1 since PIC's SSPADD uses upper 7 bits 
 */
#define SLAVE_1_ADDRESS         0x20
#define SLAVE_2_ADDRESS         0x40

void I2C_Test_Init(void);
void I2C_Test_App(void);

#endif
