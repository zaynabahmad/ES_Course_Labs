
_main:

;main.c,17 :: 		void main(void)
;main.c,19 :: 		GPIO_Test();
	CALL       _GPIO_Test+0
;main.c,20 :: 		TIMER_Test();
	CALL       _TIMER_Test+0
;main.c,21 :: 		ADC_Test();
	CALL       _ADC_Test+0
;main.c,22 :: 		UART_Test();
	CALL       _UART_Test+0
;main.c,23 :: 		I2C_Test();
	CALL       _I2C_Test+0
;main.c,24 :: 		PWM_Test();
	CALL       _PWM_Test+0
;main.c,25 :: 		EXTI_Test();
	CALL       _EXTI_Test+0
;main.c,26 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
