
_app_timer0_test:

;timer0_test.c,6 :: 		void app_timer0_test(void) {
;timer0_test.c,8 :: 		LED_Init(GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_LED_Init_port+0
	MOVLW      1
	MOVWF      FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;timer0_test.c,10 :: 		TIMER0_init();
	CALL       _TIMER0_init+0
;timer0_test.c,11 :: 		TIMER0_setPreload(0);
	CLRF       FARG_TIMER0_setPreload_value+0
	CALL       _TIMER0_setPreload+0
;timer0_test.c,12 :: 		TIMER0_enableInterrupt();
	CALL       _TIMER0_enableInterrupt+0
;timer0_test.c,14 :: 		while(1) {
L_app_timer0_test0:
;timer0_test.c,16 :: 		if (timer0_flag == 1) {
	MOVF       _timer0_flag+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_app_timer0_test2
;timer0_test.c,21 :: 		LED_Toggle(GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_LED_Toggle_port+0
	MOVLW      1
	MOVWF      FARG_LED_Toggle_pin+0
	CALL       _LED_Toggle+0
;timer0_test.c,23 :: 		TIMER0_setPreload(0);  // reload
	CLRF       FARG_TIMER0_setPreload_value+0
	CALL       _TIMER0_setPreload+0
;timer0_test.c,24 :: 		timer0_flag = 0;
	CLRF       _timer0_flag+0
;timer0_test.c,25 :: 		}
L_app_timer0_test2:
;timer0_test.c,26 :: 		}
	GOTO       L_app_timer0_test0
;timer0_test.c,27 :: 		}
L_end_app_timer0_test:
	RETURN
; end of _app_timer0_test
