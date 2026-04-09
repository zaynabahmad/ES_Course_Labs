#include "I2C_Test/I2C_Test.h"

int main(void)
{
    /* Application Initialization Layer */
    I2C_Test_Init();

    /* Super Loop */
    while(1)
    {
        /* Application Execution Layer */
        I2C_Test_App();
    }

    return 0;
}