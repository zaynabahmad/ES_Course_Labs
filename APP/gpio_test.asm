
_dummy_delay:

;gpio_test.c,5 :: 		void dummy_delay(u32 count) {
;gpio_test.c,7 :: 		for(i = 0; i < count; i++);
	CLRF       R4+0
	CLRF       R4+1
	CLRF       R4+2
	CLRF       R4+3
L_dummy_delay0:
	MOVF       FARG_dummy_delay_count+3, 0
	SUBWF      R4+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__dummy_delay8
	MOVF       FARG_dummy_delay_count+2, 0
	SUBWF      R4+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__dummy_delay8
	MOVF       FARG_dummy_delay_count+1, 0
	SUBWF      R4+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__dummy_delay8
	MOVF       FARG_dummy_delay_count+0, 0
	SUBWF      R4+0, 0
L__dummy_delay8:
	BTFSC      STATUS+0, 0
	GOTO       L_dummy_delay1
	MOVF       R4+0, 0
	MOVWF      R0+0
	MOVF       R4+1, 0
	MOVWF      R0+1
	MOVF       R4+2, 0
	MOVWF      R0+2
	MOVF       R4+3, 0
	MOVWF      R0+3
	INCF       R0+0, 1
	BTFSC      STATUS+0, 2
	INCF       R0+1, 1
	BTFSC      STATUS+0, 2
	INCF       R0+2, 1
	BTFSC      STATUS+0, 2
	INCF       R0+3, 1
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	MOVF       R0+2, 0
	MOVWF      R4+2
	MOVF       R0+3, 0
	MOVWF      R4+3
	GOTO       L_dummy_delay0
L_dummy_delay1:
;gpio_test.c,8 :: 		}
L_end_dummy_delay:
	RETURN
; end of _dummy_delay

_app_gpio_test:

;gpio_test.c,10 :: 		void app_gpio_test(void) {
;gpio_test.c,12 :: 		ADCON1_REG = 0x06;
	MOVLW      6
	MOVWF      159
;gpio_test.c,15 :: 		GPIO_setPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);
	MOVLW      3
	MOVWF      FARG_GPIO_setPinDirection_port+0
	CLRF       FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;gpio_test.c,16 :: 		GPIO_setPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_port+0
	CLRF       FARG_GPIO_setPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;gpio_test.c,19 :: 		GPIO_setPinDirection(GPIO_PORTE, GPIO_PIN0, GPIO_OUTPUT);
	MOVLW      4
	MOVWF      FARG_GPIO_setPinDirection_port+0
	CLRF       FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;gpio_test.c,21 :: 		while(1) {
L_app_gpio_test3:
;gpio_test.c,22 :: 		if(GPIO_getPinValue(GPIO_PORTB, GPIO_PIN0) == 1) {
	MOVLW      1
	MOVWF      FARG_GPIO_getPinValue_port+0
	CLRF       FARG_GPIO_getPinValue_pin+0
	CALL       _GPIO_getPinValue+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_app_gpio_test5
;gpio_test.c,23 :: 		LED_On(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;gpio_test.c,24 :: 		GPIO_setPinValue(GPIO_PORTE, GPIO_PIN0, GPIO_HIGH);
	MOVLW      4
	MOVWF      FARG_GPIO_setPinValue_port+0
	CLRF       FARG_GPIO_setPinValue_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;gpio_test.c,25 :: 		} else {
	GOTO       L_app_gpio_test6
L_app_gpio_test5:
;gpio_test.c,26 :: 		GPIO_setPinValue(GPIO_PORTD, GPIO_PIN0, GPIO_LOW);
	MOVLW      3
	MOVWF      FARG_GPIO_setPinValue_port+0
	CLRF       FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;gpio_test.c,27 :: 		GPIO_setPinValue(GPIO_PORTE, GPIO_PIN0, GPIO_LOW);
	MOVLW      4
	MOVWF      FARG_GPIO_setPinValue_port+0
	CLRF       FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;gpio_test.c,28 :: 		}
L_app_gpio_test6:
;gpio_test.c,29 :: 		dummy_delay(1000);
	MOVLW      232
	MOVWF      FARG_dummy_delay_count+0
	MOVLW      3
	MOVWF      FARG_dummy_delay_count+1
	CLRF       FARG_dummy_delay_count+2
	CLRF       FARG_dummy_delay_count+3
	CALL       _dummy_delay+0
;gpio_test.c,30 :: 		}
	GOTO       L_app_gpio_test3
;gpio_test.c,31 :: 		}
L_end_app_gpio_test:
	RETURN
; end of _app_gpio_test
