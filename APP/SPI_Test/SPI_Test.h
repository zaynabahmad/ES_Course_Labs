#ifndef SPI_TEST_H
#define SPI_TEST_H

#include "../../SERVICES/STD_TYPES.h"

/* Define Application Roles */
#define SPI_TEST_ROLE_MASTER    0
#define SPI_TEST_ROLE_SLAVE     1

/* Change this macro to switch between Master and Slave code */
#define SPI_TEST_ROLE           SPI_TEST_ROLE_MASTER

void SPI_Test_Init(void);
void SPI_Test_App(void);

#endif
