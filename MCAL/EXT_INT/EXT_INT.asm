
_EXT_INT_Init:

;EXT_INT.c,4 :: 		void EXT_INT_Init(void)
;EXT_INT.c,7 :: 		GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	CLRF       FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;EXT_INT.c,9 :: 		EXT_INT_SetEdge(falling_edge);
	CLRF       FARG_EXT_INT_SetEdge_Edgetype+0
	CALL       _EXT_INT_SetEdge+0
;EXT_INT.c,12 :: 		CLR_BIT(INTCON, INTF_BIT);
	MOVLW      253
	ANDWF      395, 1
;EXT_INT.c,13 :: 		CLR_BIT(INTCON, INTE_BIT);
	MOVLW      239
	ANDWF      395, 1
;EXT_INT.c,15 :: 		}
L_end_EXT_INT_Init:
	RETURN
; end of _EXT_INT_Init

_EXT_INT_Enable:

;EXT_INT.c,17 :: 		void EXT_INT_Enable(void)
;EXT_INT.c,20 :: 		SET_BIT(INTCON, INTE_BIT);
	BSF        395, 4
;EXT_INT.c,22 :: 		SET_BIT(INTCON, GIE_BIT);
	BSF        395, 7
;EXT_INT.c,24 :: 		CLR_BIT(INTCON, INTF_BIT);
	MOVLW      253
	ANDWF      395, 1
;EXT_INT.c,25 :: 		}
L_end_EXT_INT_Enable:
	RETURN
; end of _EXT_INT_Enable

_EXT_INT_Disable:

;EXT_INT.c,27 :: 		void EXT_INT_Disable(void)
;EXT_INT.c,30 :: 		CLR_BIT(INTCON, INTF_BIT);
	MOVLW      253
	ANDWF      395, 1
;EXT_INT.c,32 :: 		CLR_BIT(INTCON, INTE_BIT);
	MOVLW      239
	ANDWF      395, 1
;EXT_INT.c,34 :: 		}
L_end_EXT_INT_Disable:
	RETURN
; end of _EXT_INT_Disable

_EXT_INT_SetEdge:

;EXT_INT.c,36 :: 		void EXT_INT_SetEdge(u8 Edgetype)
;EXT_INT.c,38 :: 		if (Edgetype == rising_edge)
	MOVF       FARG_EXT_INT_SetEdge_Edgetype+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT_SetEdge0
;EXT_INT.c,41 :: 		CLR_BIT(OPTION_REG, INTEDGE_BIT);
	MOVLW      191
	ANDWF      385, 1
;EXT_INT.c,42 :: 		}
	GOTO       L_EXT_INT_SetEdge1
L_EXT_INT_SetEdge0:
;EXT_INT.c,43 :: 		else if (Edgetype == falling_edge)
	MOVF       FARG_EXT_INT_SetEdge_Edgetype+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_EXT_INT_SetEdge2
;EXT_INT.c,46 :: 		SET_BIT(OPTION_REG, INTEDGE_BIT);
	BSF        385, 6
;EXT_INT.c,47 :: 		}
L_EXT_INT_SetEdge2:
L_EXT_INT_SetEdge1:
;EXT_INT.c,48 :: 		}
L_end_EXT_INT_SetEdge:
	RETURN
; end of _EXT_INT_SetEdge

_EXT_INT_SetCallback:

;EXT_INT.c,52 :: 		void EXT_INT_SetCallback(void (*ptr)(void)) {
;EXT_INT.c,53 :: 		if (ptr != 0) {
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
;EXT_INT.c,54 :: 		EXT_INT_Callback = ptr;
	MOVF       FARG_EXT_INT_SetCallback_ptr+0, 0
	MOVWF      _EXT_INT_Callback+0
	MOVF       FARG_EXT_INT_SetCallback_ptr+1, 0
	MOVWF      _EXT_INT_Callback+1
	MOVF       FARG_EXT_INT_SetCallback_ptr+2, 0
	MOVWF      _EXT_INT_Callback+2
	MOVF       FARG_EXT_INT_SetCallback_ptr+3, 0
;EXT_INT.c,55 :: 		}
L_EXT_INT_SetCallback3:
;EXT_INT.c,56 :: 		}
L_end_EXT_INT_SetCallback:
	RETURN
; end of _EXT_INT_SetCallback

_EXT_INT_ISR:

;EXT_INT.c,58 :: 		void EXT_INT_ISR(void)
;EXT_INT.c,61 :: 		CLR_BIT(INTCON , INTF_BIT);
	MOVLW      253
	ANDWF      395, 1
;EXT_INT.c,63 :: 		if(EXT_INT_Callback != 0)
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
;EXT_INT.c,65 :: 		EXT_INT_Callback();
	MOVF       _EXT_INT_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       _EXT_INT_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;EXT_INT.c,66 :: 		}
L_EXT_INT_ISR4:
;EXT_INT.c,68 :: 		}
L_end_EXT_INT_ISR:
	RETURN
; end of _EXT_INT_ISR
