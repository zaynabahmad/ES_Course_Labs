
_pwm_test_run:

;pwm_test.c,3 :: 		void pwm_test_run(void) {
;pwm_test.c,4 :: 		PWM_Init();
	CALL       _PWM_Init+0
;pwm_test.c,6 :: 		PWM_SetDutyCycle(50);
	MOVLW      50
	MOVWF      FARG_PWM_SetDutyCycle_Duty+0
	CALL       _PWM_SetDutyCycle+0
;pwm_test.c,7 :: 		PWM_Start();
	CALL       _PWM_Start+0
;pwm_test.c,8 :: 		}
L_end_pwm_test_run:
	RETURN
; end of _pwm_test_run
