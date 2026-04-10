
_EXT_INT_Init:

;EXT_INT.c,3 :: 		void EXT_INT_Init(u8 Copy_u8EdgeType)
;EXT_INT.c,5 :: 		GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	CLRF       FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;EXT_INT.c,6 :: 		EXT_INT_SetEdge(Copy_u8EdgeType);
	MOVF       FARG_EXT_INT_Init_Copy_u8EdgeType+0, 0
	MOVWF      FARG_EXT_INT_SetEdge_Edgetype+0
	CALL       _EXT_INT_SetEdge+0
;EXT_INT.c,7 :: 		CLR_BIT(INTCON, INTF_BIT);
	MOVLW      253
	ANDWF      11, 1
;EXT_INT.c,8 :: 		CLR_BIT(INTCON, INTE_BIT);
	MOVLW      239
	ANDWF      11, 1
;EXT_INT.c,9 :: 		}
L_end_EXT_INT_Init:
	RETURN
; end of _EXT_INT_Init

_EXT_INT_Enable:

;EXT_INT.c,11 :: 		void EXT_INT_Enable(void)
;EXT_INT.c,14 :: 		SET_BIT(INTCON, INTE_BIT);
	BSF        11, 4
;EXT_INT.c,16 :: 		SET_BIT(INTCON, GIE_BIT);
	BSF        11, 7
;EXT_INT.c,18 :: 		CLR_BIT(INTCON, INTF_BIT); // Clear any pending interrupt flag
	MOVLW      253
	ANDWF      11, 1
;EXT_INT.c,19 :: 		}
L_end_EXT_INT_Enable:
	RETURN
; end of _EXT_INT_Enable

_EXT_INT_Disable:

;EXT_INT.c,21 :: 		void EXT_INT_Disable(void)
;EXT_INT.c,24 :: 		CLR_BIT(INTCON, INTF_BIT);
	MOVLW      253
	ANDWF      11, 1
;EXT_INT.c,26 :: 		CLR_BIT(INTCON, INTE_BIT);
	MOVLW      239
	ANDWF      11, 1
;EXT_INT.c,28 :: 		}
L_end_EXT_INT_Disable:
	RETURN
; end of _EXT_INT_Disable

_EXT_INT_SetEdge:

;EXT_INT.c,30 :: 		void EXT_INT_SetEdge(u8 Edgetype)
;EXT_INT.c,32 :: 		if (Edgetype == rising_edge)
	MOVF       FARG_EXT_INT_SetEdge_Edgetype+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT_SetEdge0
;EXT_INT.c,35 :: 		CLR_BIT(OPTION_REG, INTEDGE_BIT); // INTEDG0 = 0 for rising edge
	MOVLW      191
	ANDWF      129, 1
;EXT_INT.c,36 :: 		}
	GOTO       L_EXT_INT_SetEdge1
L_EXT_INT_SetEdge0:
;EXT_INT.c,37 :: 		else if (Edgetype == falling_edge)
	MOVF       FARG_EXT_INT_SetEdge_Edgetype+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT_SetEdge2
;EXT_INT.c,40 :: 		SET_BIT(OPTION_REG, INTEDGE_BIT); // INTEDG0 = 1 for falling edge
	BSF        129, 6
;EXT_INT.c,41 :: 		}
L_EXT_INT_SetEdge2:
L_EXT_INT_SetEdge1:
;EXT_INT.c,42 :: 		}
L_end_EXT_INT_SetEdge:
	RETURN
; end of _EXT_INT_SetEdge

_EXT_INT_SetCallback:

;EXT_INT.c,46 :: 		void EXT_INT_SetCallback(void (*ptr)(void)) {
;EXT_INT.c,47 :: 		if (ptr != 0) {
	MOVF       FARG_EXT_INT_SetCallback_ptr+0, 0
	MOVWF      R1+0
	MOVF       FARG_EXT_INT_SetCallback_ptr+1, 0
	MOVWF      R1+1
	MOVF       FARG_EXT_INT_SetCallback_ptr+2, 0
	MOVWF      R1+2
	MOVF       FARG_EXT_INT_SetCallback_ptr+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT_SetCallback10
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT_SetCallback10
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT_SetCallback10
	MOVF       R1+0, 0
	XORLW      0
L__EXT_INT_SetCallback10:
	BTFSC      STATUS+0, 2
	GOTO       L_EXT_INT_SetCallback3
;EXT_INT.c,48 :: 		EXT_INT_Callback = ptr;
	MOVF       FARG_EXT_INT_SetCallback_ptr+0, 0
	MOVWF      _EXT_INT_Callback+0
	MOVF       FARG_EXT_INT_SetCallback_ptr+1, 0
	MOVWF      _EXT_INT_Callback+1
	MOVF       FARG_EXT_INT_SetCallback_ptr+2, 0
	MOVWF      _EXT_INT_Callback+2
	MOVF       FARG_EXT_INT_SetCallback_ptr+3, 0
;EXT_INT.c,49 :: 		}
L_EXT_INT_SetCallback3:
;EXT_INT.c,50 :: 		}
L_end_EXT_INT_SetCallback:
	RETURN
; end of _EXT_INT_SetCallback

_EXT_INT_ISR:

;EXT_INT.c,54 :: 		void EXT_INT_ISR(void)
;EXT_INT.c,56 :: 		CLR_BIT(INTCON , INTF_BIT);
	MOVLW      253
	ANDWF      11, 1
;EXT_INT.c,60 :: 		if(EXT_INT_Callback != 0)
	MOVF       _EXT_INT_Callback+0, 0
	MOVWF      R1+0
	MOVF       _EXT_INT_Callback+1, 0
	MOVWF      R1+1
	MOVF       _EXT_INT_Callback+2, 0
	MOVWF      R1+2
	MOVF       _EXT_INT_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT_ISR12
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT_ISR12
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__EXT_INT_ISR12
	MOVF       R1+0, 0
	XORLW      0
L__EXT_INT_ISR12:
	BTFSC      STATUS+0, 2
	GOTO       L_EXT_INT_ISR4
;EXT_INT.c,62 :: 		EXT_INT_Callback();
	MOVF       _EXT_INT_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       _EXT_INT_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXT_INT.c,63 :: 		}
L_EXT_INT_ISR4:
;EXT_INT.c,65 :: 		}
L_end_EXT_INT_ISR:
	RETURN
; end of _EXT_INT_ISR
