
_TIMER0_ISR_Handler:

;timer_implementation.c,9 :: 		void TIMER0_ISR_Handler(void)
;timer_implementation.c,12 :: 		if(timer_callback != 0)
	MOVF       timer_implementation_timer_callback+0, 0
	MOVWF      R1+0
	MOVF       timer_implementation_timer_callback+1, 0
	MOVWF      R1+1
	MOVF       timer_implementation_timer_callback+2, 0
	MOVWF      R1+2
	MOVF       timer_implementation_timer_callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__TIMER0_ISR_Handler2
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__TIMER0_ISR_Handler2
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__TIMER0_ISR_Handler2
	MOVF       R1+0, 0
	XORLW      0
L__TIMER0_ISR_Handler2:
	BTFSC      STATUS+0, 2
	GOTO       L_TIMER0_ISR_Handler0
;timer_implementation.c,14 :: 		timer_callback();
	MOVF       timer_implementation_timer_callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       timer_implementation_timer_callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;timer_implementation.c,15 :: 		}
L_TIMER0_ISR_Handler0:
;timer_implementation.c,16 :: 		}
L_end_TIMER0_ISR_Handler:
	RETURN
; end of _TIMER0_ISR_Handler

_TIMER0_Init:

;timer_implementation.c,18 :: 		void TIMER0_Init(void)
;timer_implementation.c,21 :: 		CLR_BIT(OPTION_REG,5);
	BCF        OPTION_REG+0, 5
;timer_implementation.c,24 :: 		CLR_BIT(OPTION_REG,3);
	BCF        OPTION_REG+0, 3
;timer_implementation.c,27 :: 		SET_BIT(OPTION_REG,2);
	BSF        OPTION_REG+0, 2
;timer_implementation.c,28 :: 		SET_BIT(OPTION_REG,1);
	BSF        OPTION_REG+0, 1
;timer_implementation.c,29 :: 		SET_BIT(OPTION_REG,0);
	BSF        OPTION_REG+0, 0
;timer_implementation.c,32 :: 		SET_BIT(INTCON,5);
	BSF        INTCON+0, 5
;timer_implementation.c,35 :: 		SET_BIT(INTCON,7);
	BSF        INTCON+0, 7
;timer_implementation.c,36 :: 		}
L_end_TIMER0_Init:
	RETURN
; end of _TIMER0_Init

_TIMER0_SetPreload:

;timer_implementation.c,38 :: 		void TIMER0_SetPreload(u8 preload)
;timer_implementation.c,40 :: 		TMR0 = preload;
	MOVF       FARG_TIMER0_SetPreload_preload+0, 0
	MOVWF      TMR0+0
;timer_implementation.c,41 :: 		}
L_end_TIMER0_SetPreload:
	RETURN
; end of _TIMER0_SetPreload

_TIMER0_SetCallback:

;timer_implementation.c,43 :: 		void TIMER0_SetCallback(void (*ptr)(void))
;timer_implementation.c,46 :: 		timer_callback = ptr;
	MOVF       FARG_TIMER0_SetCallback_ptr+0, 0
	MOVWF      timer_implementation_timer_callback+0
	MOVF       FARG_TIMER0_SetCallback_ptr+1, 0
	MOVWF      timer_implementation_timer_callback+1
	MOVF       FARG_TIMER0_SetCallback_ptr+2, 0
	MOVWF      timer_implementation_timer_callback+2
	MOVF       FARG_TIMER0_SetCallback_ptr+3, 0
;timer_implementation.c,47 :: 		}
L_end_TIMER0_SetCallback:
	RETURN
; end of _TIMER0_SetCallback
