



void APP_Test_ADC(void);
void APP_Test_TIMER0(void);
void APP_Test_EXTI(void);
void APP_Test_PWM(void);
void APP_Test_SPI(void);
void APP_Test_I2C(void);

int main(void)
{



    while(1)
    {


        APP_Test_ADC();
        APP_Test_TIMER0();
        APP_Test_EXTI();
        APP_Test_PWM();
        APP_Test_SPI();
        APP_Test_I2C();
    }

    return 0;
}