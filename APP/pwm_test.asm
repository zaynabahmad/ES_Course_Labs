
_app_pwm_test:

;pwm_test.c,4 :: 		void app_pwm_test(void)
;pwm_test.c,6 :: 		u8 duty = 0;
	CLRF       app_pwm_test_duty_L0+0
	CLRF       app_pwm_test_delayValue_L0+0
;pwm_test.c,9 :: 		PWM_Init();
	CALL       _PWM_Init+0
;pwm_test.c,11 :: 		while(1)
L_app_pwm_test0:
;pwm_test.c,13 :: 		for(duty = 0; duty <= 100; duty += 10)
	CLRF       app_pwm_test_duty_L0+0
L_app_pwm_test2:
	MOVF       app_pwm_test_duty_L0+0, 0
	SUBLW      100
	BTFSS      STATUS+0, 0
	GOTO       L_app_pwm_test3
;pwm_test.c,15 :: 		PWM_SetDutyPercent(duty);
	MOVF       app_pwm_test_duty_L0+0, 0
	MOVWF      FARG_PWM_SetDutyPercent_dutyPercent+0
	CALL       _PWM_SetDutyPercent+0
;pwm_test.c,17 :: 		for(delayValue = 0; delayValue < 10000; delayValue++)
	CLRF       app_pwm_test_delayValue_L0+0
L_app_pwm_test5:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      39
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_pwm_test15
	MOVLW      16
	SUBWF      app_pwm_test_delayValue_L0+0, 0
L__app_pwm_test15:
	BTFSC      STATUS+0, 0
	GOTO       L_app_pwm_test6
	INCF       app_pwm_test_delayValue_L0+0, 1
;pwm_test.c,20 :: 		}
	GOTO       L_app_pwm_test5
L_app_pwm_test6:
;pwm_test.c,13 :: 		for(duty = 0; duty <= 100; duty += 10)
	MOVLW      10
	ADDWF      app_pwm_test_duty_L0+0, 1
;pwm_test.c,21 :: 		}
	GOTO       L_app_pwm_test2
L_app_pwm_test3:
;pwm_test.c,23 :: 		for(duty = 100; duty >= 10; duty -= 10)
	MOVLW      100
	MOVWF      app_pwm_test_duty_L0+0
L_app_pwm_test8:
	MOVLW      10
	SUBWF      app_pwm_test_duty_L0+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_app_pwm_test9
;pwm_test.c,25 :: 		PWM_SetDutyPercent(duty);
	MOVF       app_pwm_test_duty_L0+0, 0
	MOVWF      FARG_PWM_SetDutyPercent_dutyPercent+0
	CALL       _PWM_SetDutyPercent+0
;pwm_test.c,27 :: 		for(delayValue = 0; delayValue < 10000; delayValue++)
	CLRF       app_pwm_test_delayValue_L0+0
L_app_pwm_test11:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORLW      39
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__app_pwm_test16
	MOVLW      16
	SUBWF      app_pwm_test_delayValue_L0+0, 0
L__app_pwm_test16:
	BTFSC      STATUS+0, 0
	GOTO       L_app_pwm_test12
	INCF       app_pwm_test_delayValue_L0+0, 1
;pwm_test.c,30 :: 		}
	GOTO       L_app_pwm_test11
L_app_pwm_test12:
;pwm_test.c,23 :: 		for(duty = 100; duty >= 10; duty -= 10)
	MOVLW      10
	SUBWF      app_pwm_test_duty_L0+0, 1
;pwm_test.c,31 :: 		}
	GOTO       L_app_pwm_test8
L_app_pwm_test9:
;pwm_test.c,32 :: 		}
	GOTO       L_app_pwm_test0
;pwm_test.c,33 :: 		}
L_end_app_pwm_test:
	RETURN
; end of _app_pwm_test
