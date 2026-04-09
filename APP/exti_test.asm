
_toggle_led:

;exti_test.c,5 :: 		void toggle_led(void) {
;exti_test.c,7 :: 		if(state == 0) {
	MOVF       toggle_led_state_L0+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_toggle_led0
;exti_test.c,8 :: 		LED_On(GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_LED_On_port+0
	MOVLW      1
	MOVWF      FARG_LED_On_pin+0
	CALL       _LED_On+0
;exti_test.c,9 :: 		state = 1;
	MOVLW      1
	MOVWF      toggle_led_state_L0+0
;exti_test.c,10 :: 		} else {
	GOTO       L_toggle_led1
L_toggle_led0:
;exti_test.c,11 :: 		LED_off(GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_LED_Off_port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;exti_test.c,12 :: 		state = 0;
	CLRF       toggle_led_state_L0+0
;exti_test.c,13 :: 		}
L_toggle_led1:
;exti_test.c,14 :: 		}
L_end_toggle_led:
	RETURN
; end of _toggle_led

_app_exti_test:

;exti_test.c,16 :: 		void app_exti_test(void) {
;exti_test.c,17 :: 		GPIO_setPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);
	MOVLW      3
	MOVWF      FARG_GPIO_setPinDirection_port+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;exti_test.c,18 :: 		GPIO_setPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_port+0
	CLRF       FARG_GPIO_setPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;exti_test.c,20 :: 		EXTI_init(EXTI_FALLING_EDGE);
	CLRF       FARG_EXTI_init_edge+0
	CALL       _EXTI_init+0
;exti_test.c,22 :: 		while(1) {
L_app_exti_test2:
;exti_test.c,23 :: 		if (exti_flag == 1) {
	MOVF       _exti_flag+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_app_exti_test4
;exti_test.c,24 :: 		toggle_led();   // ? SAFE: called in main, not interrupt
	CALL       _toggle_led+0
;exti_test.c,25 :: 		exti_flag = 0;
	CLRF       _exti_flag+0
;exti_test.c,26 :: 		}
L_app_exti_test4:
;exti_test.c,27 :: 		}
	GOTO       L_app_exti_test2
;exti_test.c,28 :: 		}
L_end_app_exti_test:
	RETURN
; end of _app_exti_test
