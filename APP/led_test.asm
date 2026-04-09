
_app_led_test:

;led_test.c,6 :: 		void app_led_test(void)
;led_test.c,8 :: 		u16 delayValue = 0;
	CLRF       app_led_test_delayValue_L0+0
;led_test.c,10 :: 		LED_Init(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Init_port+0
	CLRF       FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;led_test.c,12 :: 		while(1)
L_app_led_test0:
;led_test.c,14 :: 		LED_On(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_On_port+0
	CLRF       FARG_LED_On_pin+0
	CALL       _LED_On+0
;led_test.c,15 :: 		for(delayValue = 0; delayValue < 20000; delayValue++)
	CLRF       app_led_test_delayValue_L0+0
L_app_led_test2:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      78
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_led_test9
	MOVLW      32
	SUBWF      app_led_test_delayValue_L0+0, 0
L__app_led_test9:
	BTFSC      STATUS+0, 0
	GOTO       L_app_led_test3
	INCF       app_led_test_delayValue_L0+0, 1
;led_test.c,18 :: 		}
	GOTO       L_app_led_test2
L_app_led_test3:
;led_test.c,20 :: 		LED_Off(GPIO_PORTD, GPIO_PIN0);
	MOVLW      3
	MOVWF      FARG_LED_Off_port+0
	CLRF       FARG_LED_Off_pin+0
	CALL       _LED_Off+0
;led_test.c,21 :: 		for(delayValue = 0; delayValue < 20000; delayValue++)
	CLRF       app_led_test_delayValue_L0+0
L_app_led_test5:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      78
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_led_test10
	MOVLW      32
	SUBWF      app_led_test_delayValue_L0+0, 0
L__app_led_test10:
	BTFSC      STATUS+0, 0
	GOTO       L_app_led_test6
	INCF       app_led_test_delayValue_L0+0, 1
;led_test.c,24 :: 		}
	GOTO       L_app_led_test5
L_app_led_test6:
;led_test.c,25 :: 		}
	GOTO       L_app_led_test0
;led_test.c,26 :: 		}
L_end_app_led_test:
	RETURN
; end of _app_led_test
