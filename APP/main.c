/* Application Layer */
/* This file calls the test functions for all implemented drivers as per assignment requirements */

extern void TIMER0_Test(void);
extern void PWM_Test(void);
extern void ADC_Test(void);
extern void UART_Test(void);
extern void SPI_Test(void);
extern void I2C_Test(void);

int main(void) {
  
    TIMER0_Test();
    PWM_Test();
    ADC_Test();
    UART_Test();
    SPI_Test();
    I2C_Test();

    while (1) {
       
    }
    
    return 0;
}