
_SWITCH_Init:

;SWITCH.c,3 :: 		void SWITCH_Init(Switch_PinID_t pin)
;SWITCH.c,6 :: 		TRISB |= (1 << pin);
	MOVF       FARG_SWITCH_Init_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__SWITCH_Init1:
	BTFSC      STATUS+0, 2
	GOTO       L__SWITCH_Init2
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__SWITCH_Init1
L__SWITCH_Init2:
	MOVF       R0+0, 0
	IORWF      TRISB+0, 1
;SWITCH.c,7 :: 		}
L_end_SWITCH_Init:
	RETURN
; end of _SWITCH_Init
