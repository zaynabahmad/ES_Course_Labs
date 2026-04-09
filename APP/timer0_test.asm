
_Timer0_Toggle_Callback:

;timer0_test.c,7 :: 		void Timer0_Toggle_Callback(void) {
;timer0_test.c,8 :: 		Overflow_Counter++;
	INCF       timer0_test_Overflow_Counter+0, 1
;timer0_test.c,10 :: 		if (Overflow_Counter >= 30) {
	MOVLW      30
	SUBWF      timer0_test_Overflow_Counter+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_Timer0_Toggle_Callback0
;timer0_test.c,11 :: 		LED_Toggle(GPIO_PORTC, GPIO_PIN0);
	MOVLW      2
	MOVWF      FARG_LED_Toggle_Port+0
	CLRF       FARG_LED_Toggle_Pin+0
	CALL       _LED_Toggle+0
;timer0_test.c,12 :: 		Overflow_Counter = 0;
	CLRF       timer0_test_Overflow_Counter+0
;timer0_test.c,13 :: 		}
L_Timer0_Toggle_Callback0:
;timer0_test.c,14 :: 		}
L_end_Timer0_Toggle_Callback:
	RETURN
; end of _Timer0_Toggle_Callback

_timer0_test_run:

;timer0_test.c,16 :: 		void timer0_test_run(void) {
;timer0_test.c,17 :: 		LED_Init(GPIO_PORTC, GPIO_PIN0);
	MOVLW      2
	MOVWF      FARG_LED_Init_Port+0
	CLRF       FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;timer0_test.c,19 :: 		TIMER0_Init(TIMER0_PRESCALER_256);
	MOVLW      7
	MOVWF      FARG_TIMER0_Init_Prescaler+0
	CALL       _TIMER0_Init+0
;timer0_test.c,20 :: 		TIMER0_SetCallback(Timer0_Toggle_Callback);
	MOVLW      _Timer0_Toggle_Callback+0
	MOVWF      FARG_TIMER0_SetCallback_ptr+0
	MOVLW      hi_addr(_Timer0_Toggle_Callback+0)
	MOVWF      FARG_TIMER0_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_TIMER0_SetCallback_ptr+2
	MOVLW      0
	CALL       _TIMER0_SetCallback+0
;timer0_test.c,21 :: 		TIMER0_EnableInterrupt();
	CALL       _TIMER0_EnableInterrupt+0
;timer0_test.c,23 :: 		while(1) {
L_timer0_test_run1:
;timer0_test.c,24 :: 		}
	GOTO       L_timer0_test_run1
;timer0_test.c,25 :: 		}
L_end_timer0_test_run:
	RETURN
; end of _timer0_test_run
