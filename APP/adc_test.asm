
_adc_test_run:

;adc_test.c,4 :: 		void adc_test_run(void) {
;adc_test.c,6 :: 		ADC_Init();
	CALL       _ADC_Init+0
;adc_test.c,9 :: 		adc_val = ADC_ReadChannel(0);
	CLRF       FARG_ADC_ReadChannel_Channel+0
	CALL       _ADC_ReadChannel+0
;adc_test.c,10 :: 		UART_Write((u8)(adc_val >> 2));
	MOVF       R0+0, 0
	MOVWF      FARG_UART_Write_Data+0
	RRF        FARG_UART_Write_Data+0, 1
	BCF        FARG_UART_Write_Data+0, 7
	RRF        FARG_UART_Write_Data+0, 1
	BCF        FARG_UART_Write_Data+0, 7
	CALL       _UART_Write+0
;adc_test.c,11 :: 		}
L_end_adc_test_run:
	RETURN
; end of _adc_test_run
