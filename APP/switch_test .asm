
_app_switch_test:

;switch_test .c,6 :: 		void app_switch_test(void)
;switch_test .c,8 :: 		u8 switchState = 0;
;switch_test .c,10 :: 		SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
	MOVLW      1
	MOVWF      FARG_SWITCH_Init_port+0
	CLRF       FARG_SWITCH_Init_pin+0
	CALL       _SWITCH_Init+0
;switch_test .c,11 :: 		LED_Init(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;switch_test .c,13 :: 		while(1)
L_app_switch_test0:
;switch_test .c,15 :: 		switchState = SWITCH_GetState(GPIO_PORTB, GPIO_PIN0);
	MOVLW      1
	MOVWF      FARG_SWITCH_GetState_port+0
	CLRF       FARG_SWITCH_GetState_pin+0
	CALL       _SWITCH_GetState+0
;switch_test .c,17 :: 		if(switchState == GPIO_HIGH)
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_app_switch_test2
;switch_test .c,19 :: 		LED_On(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;switch_test .c,20 :: 		}
	GOTO       L_app_switch_test3
L_app_switch_test2:
;switch_test .c,23 :: 		LED_Off(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;switch_test .c,24 :: 		}
L_app_switch_test3:
;switch_test .c,25 :: 		}
	GOTO       L_app_switch_test0
;switch_test .c,26 :: 		}
L_end_app_switch_test:
	RETURN
; end of _app_switch_test
