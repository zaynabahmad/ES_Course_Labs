
_ADC_Test:

;adc_test.c,5 :: 		void ADC_Test(void)
;adc_test.c,9 :: 		GPIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	CLRF       FARG_GPIO_SetPinDirection_pin+0
	CLRF       FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;adc_test.c,11 :: 		ADC_Init();
	CALL       _ADC_Init+0
;adc_test.c,13 :: 		while(1)
L_ADC_Test0:
;adc_test.c,15 :: 		value = ADC_Read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
;adc_test.c,17 :: 		if(value > 512)
	MOVF       R0+1, 0
	SUBLW      2
	BTFSS      STATUS+0, 2
	GOTO       L__ADC_Test5
	MOVF       R0+0, 0
	SUBLW      0
L__ADC_Test5:
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_Test2
;adc_test.c,18 :: 		GPIO_WritePin(PORTB, PIN0, HIGH);
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_port+0
	CLRF       FARG_GPIO_WritePin_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
	GOTO       L_ADC_Test3
L_ADC_Test2:
;adc_test.c,20 :: 		GPIO_WritePin(PORTB, PIN0, LOW);
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_port+0
	CLRF       FARG_GPIO_WritePin_pin+0
	CLRF       FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
L_ADC_Test3:
;adc_test.c,21 :: 		}
	GOTO       L_ADC_Test0
;adc_test.c,22 :: 		}
L_end_ADC_Test:
	RETURN
; end of _ADC_Test
