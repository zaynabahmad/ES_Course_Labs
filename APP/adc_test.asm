
_ADC_Test:

;adc_test.c,4 :: 		void ADC_Test(void)
;adc_test.c,10 :: 		GPIO_voidSetPinDirection('B', 0, 0);   /* RB0 = output */
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinDirection_port+0
	CLRF       FARG_GPIO_voidSetPinDirection_pin+0
	CLRF       FARG_GPIO_voidSetPinDirection_dir+0
	CALL       _GPIO_voidSetPinDirection+0
;adc_test.c,11 :: 		GPIO_voidSetPinDirection('B', 1, 0);   /* RB1 = output (new) */
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinDirection_port+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinDirection_pin+0
	CLRF       FARG_GPIO_voidSetPinDirection_dir+0
	CALL       _GPIO_voidSetPinDirection+0
;adc_test.c,14 :: 		ADC_voidInit();
	CALL       _ADC_voidInit+0
;adc_test.c,16 :: 		while (1)
L_ADC_Test0:
;adc_test.c,19 :: 		adc_raw = ADC_u16Read(0);
	CLRF       FARG_ADC_u16Read_channel+0
	CALL       _ADC_u16Read+0
	MOVF       R0+0, 0
	MOVWF      ADC_Test_adc_raw_L0+0
	MOVF       R0+1, 0
	MOVWF      ADC_Test_adc_raw_L0+1
;adc_test.c,22 :: 		if (adc_raw == ADC_INVALID_CHANNEL)
	MOVF       R0+1, 0
	XORLW      255
	BTFSS      STATUS+0, 2
	GOTO       L__ADC_Test8
	MOVLW      255
	XORWF      R0+0, 0
L__ADC_Test8:
	BTFSS      STATUS+0, 2
	GOTO       L_ADC_Test2
;adc_test.c,25 :: 		GPIO_voidSetPinValue('B', 0, 0);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	CLRF       FARG_GPIO_voidSetPinValue_pin+0
	CLRF       FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,26 :: 		GPIO_voidSetPinValue('B', 1, 0);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinValue_pin+0
	CLRF       FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,27 :: 		continue;
	GOTO       L_ADC_Test0
;adc_test.c,28 :: 		}
L_ADC_Test2:
;adc_test.c,31 :: 		voltage_mv = ADC_f32ToVoltage(adc_raw);
	MOVF       ADC_Test_adc_raw_L0+0, 0
	MOVWF      FARG_ADC_f32ToVoltage_raw_value+0
	MOVF       ADC_Test_adc_raw_L0+1, 0
	MOVWF      FARG_ADC_f32ToVoltage_raw_value+1
	CALL       _ADC_f32ToVoltage+0
;adc_test.c,35 :: 		if (adc_raw > 512u)
	MOVF       ADC_Test_adc_raw_L0+1, 0
	SUBLW      2
	BTFSS      STATUS+0, 2
	GOTO       L__ADC_Test9
	MOVF       ADC_Test_adc_raw_L0+0, 0
	SUBLW      0
L__ADC_Test9:
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_Test3
;adc_test.c,38 :: 		GPIO_voidSetPinValue('B', 0, 1);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	CLRF       FARG_GPIO_voidSetPinValue_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,39 :: 		GPIO_voidSetPinValue('B', 1, 0);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinValue_pin+0
	CLRF       FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,40 :: 		}
	GOTO       L_ADC_Test4
L_ADC_Test3:
;adc_test.c,41 :: 		else if (adc_raw > 256u)
	MOVF       ADC_Test_adc_raw_L0+1, 0
	SUBLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__ADC_Test10
	MOVF       ADC_Test_adc_raw_L0+0, 0
	SUBLW      0
L__ADC_Test10:
	BTFSC      STATUS+0, 0
	GOTO       L_ADC_Test5
;adc_test.c,44 :: 		GPIO_voidSetPinValue('B', 0, 0);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	CLRF       FARG_GPIO_voidSetPinValue_pin+0
	CLRF       FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,45 :: 		GPIO_voidSetPinValue('B', 1, 1);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinValue_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,46 :: 		}
	GOTO       L_ADC_Test6
L_ADC_Test5:
;adc_test.c,50 :: 		GPIO_voidSetPinValue('B', 0, 0);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	CLRF       FARG_GPIO_voidSetPinValue_pin+0
	CLRF       FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,51 :: 		GPIO_voidSetPinValue('B', 1, 0);
	MOVLW      66
	MOVWF      FARG_GPIO_voidSetPinValue_port+0
	MOVLW      1
	MOVWF      FARG_GPIO_voidSetPinValue_pin+0
	CLRF       FARG_GPIO_voidSetPinValue_val+0
	CALL       _GPIO_voidSetPinValue+0
;adc_test.c,52 :: 		}
L_ADC_Test6:
L_ADC_Test4:
;adc_test.c,53 :: 		}
	GOTO       L_ADC_Test0
;adc_test.c,54 :: 		}
L_end_ADC_Test:
	RETURN
; end of _ADC_Test
