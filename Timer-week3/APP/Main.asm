
_Toggle_LED2_1Sec:

;Main.c,6 :: 		void Toggle_LED2_1Sec(void)
;Main.c,8 :: 		LED_Toggle(GPIO_PORTB, GPIO_PIN2);
	MOVLW      1
	MOVWF      FARG_LED_Toggle_Port+0
	MOVLW      2
	MOVWF      FARG_LED_Toggle_Pin+0
	CALL       _LED_Toggle+0
;Main.c,9 :: 		}
L_end_Toggle_LED2_1Sec:
	RETURN
; end of _Toggle_LED2_1Sec

_Toggle_LED1_2Sec:

;Main.c,12 :: 		void Toggle_LED1_2Sec(void)
;Main.c,14 :: 		LED_Toggle(GPIO_PORTB, GPIO_PIN1);
	MOVLW      1
	MOVWF      FARG_LED_Toggle_Port+0
	MOVLW      1
	MOVWF      FARG_LED_Toggle_Pin+0
	CALL       _LED_Toggle+0
;Main.c,15 :: 		}
L_end_Toggle_LED1_2Sec:
	RETURN
; end of _Toggle_LED1_2Sec

_main:

;Main.c,17 :: 		void main()
;Main.c,20 :: 		LED_Init(GPIO_PORTB, GPIO_PIN1);
	MOVLW      1
	MOVWF      FARG_LED_Init_Port+0
	MOVLW      1
	MOVWF      FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;Main.c,21 :: 		LED_Init(GPIO_PORTB, GPIO_PIN2);
	MOVLW      1
	MOVWF      FARG_LED_Init_Port+0
	MOVLW      2
	MOVWF      FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;Main.c,24 :: 		TIMER0_SetCallback_1Sec(Toggle_LED2_1Sec);
	MOVLW      _Toggle_LED2_1Sec+0
	MOVWF      FARG_TIMER0_SetCallback_1Sec_ptr+0
	MOVLW      hi_addr(_Toggle_LED2_1Sec+0)
	MOVWF      FARG_TIMER0_SetCallback_1Sec_ptr+1
	MOVLW      0
	MOVWF      FARG_TIMER0_SetCallback_1Sec_ptr+2
	MOVLW      0
	CALL       _TIMER0_SetCallback_1Sec+0
;Main.c,25 :: 		TIMER0_SetCallback_2Sec(Toggle_LED1_2Sec);
	MOVLW      _Toggle_LED1_2Sec+0
	MOVWF      FARG_TIMER0_SetCallback_2Sec_ptr+0
	MOVLW      hi_addr(_Toggle_LED1_2Sec+0)
	MOVWF      FARG_TIMER0_SetCallback_2Sec_ptr+1
	MOVLW      0
	MOVWF      FARG_TIMER0_SetCallback_2Sec_ptr+2
	MOVLW      0
	CALL       _TIMER0_SetCallback_2Sec+0
;Main.c,28 :: 		TIMER0_Init();
	CALL       _TIMER0_Init+0
;Main.c,31 :: 		while(1)
L_main0:
;Main.c,34 :: 		}
	GOTO       L_main0
;Main.c,35 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
