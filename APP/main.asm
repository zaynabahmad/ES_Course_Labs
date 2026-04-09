
_main:

;main.c,13 :: 		void main(void) {
;main.c,15 :: 		GPIO_Init();
	CALL       _GPIO_Init+0
;main.c,18 :: 		usart_test_run(); // Changed from test_USART
	CALL       _usart_test_run+0
;main.c,19 :: 		spi_test_run();   // Changed from test_SPI
	CALL       _spi_test_run+0
;main.c,20 :: 		i2c_test_run();   // Changed from test_I2C
	CALL       _i2c_test_run+0
;main.c,23 :: 		adc_test_run();   // Changed from test_ADC
	CALL       _adc_test_run+0
;main.c,24 :: 		pwm_test_run();   // Changed from test_PWM
	CALL       _pwm_test_run+0
;main.c,27 :: 		timer0_test_run();
	CALL       _timer0_test_run+0
;main.c,28 :: 		ext_int_test_run();
	CALL       _ext_int_test_run+0
;main.c,30 :: 		while(1) {
L_main0:
;main.c,32 :: 		}
	GOTO       L_main0
;main.c,33 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
