
_app_adc_test:

;adc_test.c,5 :: 		void app_adc_test(void)
;adc_test.c,7 :: 		u16 adc_value = 0;
;adc_test.c,10 :: 		GPIO_setPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);
	CLRF       FARG_GPIO_setPinDirection_port+0
	CLRF       FARG_GPIO_setPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;adc_test.c,13 :: 		LED_Init(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;adc_test.c,15 :: 		ADC_Init();
	CALL       _ADC_Init+0
;adc_test.c,17 :: 		while(1)
L_app_adc_test0:
;adc_test.c,19 :: 		adc_value = ADC_Read(ADC_CHANNEL_0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
;adc_test.c,22 :: 		if(adc_value > 512)
	MOVLW      128
	XORLW      2
	MOVWF      R1+0
	MOVLW      128
	SUBWF      R1+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_adc_test5
	MOVF       R0+0, 0
	SUBLW      0
L__app_adc_test5:
	BTFSC      STATUS+0, 0
	GOTO       L_app_adc_test2
;adc_test.c,24 :: 		LED_On(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;adc_test.c,25 :: 		}
	GOTO       L_app_adc_test3
L_app_adc_test2:
;adc_test.c,28 :: 		LED_Off(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;adc_test.c,29 :: 		}
L_app_adc_test3:
;adc_test.c,30 :: 		}
	GOTO       L_app_adc_test0
;adc_test.c,31 :: 		}
L_end_app_adc_test:
	RETURN
; end of _app_adc_test
