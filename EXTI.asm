
_EXTI_Init:

;EXTI.c,7 :: 		void EXTI_Init(void)
;EXTI.c,9 :: 		TRISB.F0 = 1;        // RB0 input
	BSF        TRISB+0, 0
;EXTI.c,12 :: 		OPTION_REG.INTEDG = 1;   // Rising edge
	BSF        OPTION_REG+0, 6
;EXTI.c,17 :: 		INTCON.INTE = 1;     // Enable external interrupt
	BSF        INTCON+0, 4
;EXTI.c,18 :: 		INTCON.GIE  = 1;     // Enable global interrupt
	BSF        INTCON+0, 7
;EXTI.c,19 :: 		}
L_end_EXTI_Init:
	RETURN
; end of _EXTI_Init

_EXTI_SetCallBack:

;EXTI.c,21 :: 		void EXTI_SetCallBack(void (*Copy_ptr)(void))
;EXTI.c,23 :: 		if(Copy_ptr != 0)
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+0, 0
	MOVWF      R1+0
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+1, 0
	MOVWF      R1+1
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+2, 0
	MOVWF      R1+2
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXTI_SetCallBack5
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXTI_SetCallBack5
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXTI_SetCallBack5
	MOVF       R1+0, 0
	XORLW      0
L__EXTI_SetCallBack5:
	BTFSC      STATUS+0, 2
	GOTO       L_EXTI_SetCallBack0
;EXTI.c,25 :: 		EXTI_CallBack = Copy_ptr;
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+0, 0
	MOVWF      EXTI_EXTI_CallBack+0
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+1, 0
	MOVWF      EXTI_EXTI_CallBack+1
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+2, 0
	MOVWF      EXTI_EXTI_CallBack+2
	MOVF       FARG_EXTI_SetCallBack_Copy_ptr+3, 0
;EXTI.c,26 :: 		}
L_EXTI_SetCallBack0:
;EXTI.c,27 :: 		}
L_end_EXTI_SetCallBack:
	RETURN
; end of _EXTI_SetCallBack

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;EXTI.c,30 :: 		void interrupt()
;EXTI.c,32 :: 		if(INTCON.INTF == 1)
	BTFSS      INTCON+0, 1
	GOTO       L_interrupt1
;EXTI.c,34 :: 		INTCON.INTF = 0;    // Clear flag
	BCF        INTCON+0, 1
;EXTI.c,36 :: 		if(EXTI_CallBack != 0)
	MOVF       EXTI_EXTI_CallBack+0, 0
	MOVWF      R1+0
	MOVF       EXTI_EXTI_CallBack+1, 0
	MOVWF      R1+1
	MOVF       EXTI_EXTI_CallBack+2, 0
	MOVWF      R1+2
	MOVF       EXTI_EXTI_CallBack+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt8
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt8
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__interrupt8
	MOVF       R1+0, 0
	XORLW      0
L__interrupt8:
	BTFSC      STATUS+0, 2
	GOTO       L_interrupt2
;EXTI.c,38 :: 		EXTI_CallBack();
	MOVF       EXTI_EXTI_CallBack+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       EXTI_EXTI_CallBack+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXTI.c,39 :: 		}
L_interrupt2:
;EXTI.c,40 :: 		}
L_interrupt1:
;EXTI.c,41 :: 		}
L_end_interrupt:
L__interrupt7:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

EXTI____?ag:

L_end_EXTI___?ag:
	RETURN
; end of EXTI____?ag
