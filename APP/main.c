#include "../APP/ext_int_test.h"
#include "../APP/gpio_test.h"

int main(void)
{

    APP_TestGPIO();

    while(1)
    {
        // Handled by the test file
    }

    return 0;
}