#include "../APP/ext_int_test.h"
#include "../APP/gpio_test.h"
#include "../APP/Timer0_test.h"
#include "APP/pwm_test.h"

int main(void)
{
    APP_TestPWM();
    while(1){}
    return 0;
}
