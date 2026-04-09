
_TIMER_Test:

;timer0_test.c,7 :: 		void TIMER_Test(void)
;timer0_test.c,9 :: 		GPIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	CLRF       FARG_GPIO_SetPinDirection_pin+0
	CLRF       FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;timer0_test.c,11 :: 		TIMER0_Init();
	CALL       _TIMER0_Init+0
;timer0_test.c,12 :: 		TIMER0_Start();
	CALL       _TIMER0_Start+0
;timer0_test.c,14 :: 		while(1)
L_TIMER_Test0:
;timer0_test.c,17 :: 		}
	GOTO       L_TIMER_Test0
;timer0_test.c,18 :: 		}
L_end_TIMER_Test:
	RETURN
; end of _TIMER_Test
