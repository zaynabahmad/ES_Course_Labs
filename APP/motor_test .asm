
_app_motor_test:

;motor_test .c,4 :: 		void app_motor_test(void)
;motor_test .c,6 :: 		u16 delayValue = 0;
	CLRF       app_motor_test_delayValue_L0+0
;motor_test .c,8 :: 		MOTOR_Init(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_MOTOR_Init_port1+0
	CLRF       FARG_MOTOR_Init_pin1+0
	MOVLW      3
	MOVWF      FARG_MOTOR_Init_port2+0
	MOVLW      1
	MOVWF      FARG_MOTOR_Init_pin2+0
	CALL       _MOTOR_Init+0
;motor_test .c,10 :: 		while(1)
L_app_motor_test0:
;motor_test .c,12 :: 		MOTOR_Forward(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_MOTOR_Forward_port1+0
	CLRF       FARG_MOTOR_Forward_pin1+0
	MOVLW      3
	MOVWF      FARG_MOTOR_Forward_port2+0
	MOVLW      1
	MOVWF      FARG_MOTOR_Forward_pin2+0
	CALL       _MOTOR_Forward+0
;motor_test .c,13 :: 		for(delayValue = 0; delayValue < 20000; delayValue++) { ; }
	CLRF       app_motor_test_delayValue_L0+0
L_app_motor_test2:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      78
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_motor_test15
	MOVLW      32
	SUBWF      app_motor_test_delayValue_L0+0, 0
L__app_motor_test15:
	BTFSC      STATUS+0, 0
	GOTO       L_app_motor_test3
	INCF       app_motor_test_delayValue_L0+0, 1
	GOTO       L_app_motor_test2
L_app_motor_test3:
;motor_test .c,15 :: 		MOTOR_Stop(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_MOTOR_Stop_port1+0
	CLRF       FARG_MOTOR_Stop_pin1+0
	MOVLW      3
	MOVWF      FARG_MOTOR_Stop_port2+0
	MOVLW      1
	MOVWF      FARG_MOTOR_Stop_pin2+0
	CALL       _MOTOR_Stop+0
;motor_test .c,16 :: 		for(delayValue = 0; delayValue < 10000; delayValue++) { ; }
	CLRF       app_motor_test_delayValue_L0+0
L_app_motor_test5:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      39
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_motor_test16
	MOVLW      16
	SUBWF      app_motor_test_delayValue_L0+0, 0
L__app_motor_test16:
	BTFSC      STATUS+0, 0
	GOTO       L_app_motor_test6
	INCF       app_motor_test_delayValue_L0+0, 1
	GOTO       L_app_motor_test5
L_app_motor_test6:
;motor_test .c,18 :: 		MOTOR_Reverse(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_MOTOR_Reverse_port1+0
	CLRF       FARG_MOTOR_Reverse_pin1+0
	MOVLW      3
	MOVWF      FARG_MOTOR_Reverse_port2+0
	MOVLW      1
	MOVWF      FARG_MOTOR_Reverse_pin2+0
	CALL       _MOTOR_Reverse+0
;motor_test .c,19 :: 		for(delayValue = 0; delayValue < 20000; delayValue++) { ; }
	CLRF       app_motor_test_delayValue_L0+0
L_app_motor_test8:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      78
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_motor_test17
	MOVLW      32
	SUBWF      app_motor_test_delayValue_L0+0, 0
L__app_motor_test17:
	BTFSC      STATUS+0, 0
	GOTO       L_app_motor_test9
	INCF       app_motor_test_delayValue_L0+0, 1
	GOTO       L_app_motor_test8
L_app_motor_test9:
;motor_test .c,21 :: 		MOTOR_Stop(GPIO_PORTD, GPIO_PIN0, GPIO_PORTD, GPIO_PIN1);
	MOVLW      3
	MOVWF      FARG_MOTOR_Stop_port1+0
	CLRF       FARG_MOTOR_Stop_pin1+0
	MOVLW      3
	MOVWF      FARG_MOTOR_Stop_port2+0
	MOVLW      1
	MOVWF      FARG_MOTOR_Stop_pin2+0
	CALL       _MOTOR_Stop+0
;motor_test .c,22 :: 		for(delayValue = 0; delayValue < 10000; delayValue++) { ; }
	CLRF       app_motor_test_delayValue_L0+0
L_app_motor_test11:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      39
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_motor_test18
	MOVLW      16
	SUBWF      app_motor_test_delayValue_L0+0, 0
L__app_motor_test18:
	BTFSC      STATUS+0, 0
	GOTO       L_app_motor_test12
	INCF       app_motor_test_delayValue_L0+0, 1
	GOTO       L_app_motor_test11
L_app_motor_test12:
;motor_test .c,23 :: 		}
	GOTO       L_app_motor_test0
;motor_test .c,24 :: 		}
L_end_app_motor_test:
	RETURN
; end of _app_motor_test
