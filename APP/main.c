 #include "D:/ES-Project-Lab/SERVICES/std_types.h"

// External declaration for our test functions
// (As we add more drivers, we will add their test prototypes here)
extern void app_gpio_test(void);
extern void app_exti_test(void);
extern void app_timer0_test(void);
extern void app_adc_test(void);
extern void app_uart_test(void);
extern void app_i2c_test(void);
extern void app_spi_test(void);
extern void app_pwm_test(void);
extern void app_switch_test(void);
 extern void app_motor_test(void);
 extern void app_led_test(void);
void main(void)
{
  app_led_test();

    while(1)
    {
        ;
    }
}