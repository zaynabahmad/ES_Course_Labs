
_PWM_Test:

;pwm_test.c,4 :: 		void PWM_Test(void)
;pwm_test.c,6 :: 		unsigned int duty = 0;
	CLRF       PWM_Test_duty_L0+0
	CLRF       PWM_Test_duty_L0+1
;pwm_test.c,8 :: 		PWM_Init();
	CALL       _PWM_Init+0
;pwm_test.c,10 :: 		while(1)
L_PWM_Test0:
;pwm_test.c,12 :: 		PWM_SetDuty(duty);
	MOVF       PWM_Test_duty_L0+0, 0
	MOVWF      FARG_PWM_SetDuty_duty+0
	MOVF       PWM_Test_duty_L0+1, 0
	MOVWF      FARG_PWM_SetDuty_duty+1
	CALL       _PWM_SetDuty+0
;pwm_test.c,13 :: 		duty += 10;
	MOVLW      10
	ADDWF      PWM_Test_duty_L0+0, 0
	MOVWF      R1+0
	MOVF       PWM_Test_duty_L0+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      R1+1
	MOVF       R1+0, 0
	MOVWF      PWM_Test_duty_L0+0
	MOVF       R1+1, 0
	MOVWF      PWM_Test_duty_L0+1
;pwm_test.c,15 :: 		if(duty > 1023)
	MOVF       R1+1, 0
	SUBLW      3
	BTFSS      STATUS+0, 2
	GOTO       L__PWM_Test5
	MOVF       R1+0, 0
	SUBLW      255
L__PWM_Test5:
	BTFSC      STATUS+0, 0
	GOTO       L_PWM_Test2
;pwm_test.c,16 :: 		duty = 0;
	CLRF       PWM_Test_duty_L0+0
	CLRF       PWM_Test_duty_L0+1
L_PWM_Test2:
;pwm_test.c,18 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_PWM_Test3:
	DECFSZ     R13+0, 1
	GOTO       L_PWM_Test3
	DECFSZ     R12+0, 1
	GOTO       L_PWM_Test3
	DECFSZ     R11+0, 1
	GOTO       L_PWM_Test3
	NOP
;pwm_test.c,19 :: 		}
	GOTO       L_PWM_Test0
;pwm_test.c,20 :: 		}
L_end_PWM_Test:
	RETURN
; end of _PWM_Test
