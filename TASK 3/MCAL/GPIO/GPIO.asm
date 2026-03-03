
_MGPIO_vSetPinDirection:

;GPIO.c,5 :: 		void MGPIO_vSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction) {
;GPIO.c,6 :: 		if (Copy_u8Port == PORTB_ID) {
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Port+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_MGPIO_vSetPinDirection0
;GPIO.c,7 :: 		if (Copy_u8Direction == PIN_INPUT) SET_BIT(TRISB, Copy_u8Pin);
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_MGPIO_vSetPinDirection1
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__MGPIO_vSetPinDirection11:
	BTFSC      STATUS+0, 2
	GOTO       L__MGPIO_vSetPinDirection12
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__MGPIO_vSetPinDirection11
L__MGPIO_vSetPinDirection12:
	MOVF       R0+0, 0
	IORWF      TRISB+0, 1
	GOTO       L_MGPIO_vSetPinDirection2
L_MGPIO_vSetPinDirection1:
;GPIO.c,8 :: 		else CLR_BIT(TRISB, Copy_u8Pin);
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__MGPIO_vSetPinDirection13:
	BTFSC      STATUS+0, 2
	GOTO       L__MGPIO_vSetPinDirection14
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__MGPIO_vSetPinDirection13
L__MGPIO_vSetPinDirection14:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISB+0, 1
L_MGPIO_vSetPinDirection2:
;GPIO.c,9 :: 		} else if (Copy_u8Port == PORTD_ID) {
	GOTO       L_MGPIO_vSetPinDirection3
L_MGPIO_vSetPinDirection0:
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Port+0, 0
	XORLW      3
	BTFSS      STATUS+0, 2
	GOTO       L_MGPIO_vSetPinDirection4
;GPIO.c,10 :: 		if (Copy_u8Direction == PIN_INPUT) SET_BIT(TRISD, Copy_u8Pin);
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Direction+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_MGPIO_vSetPinDirection5
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__MGPIO_vSetPinDirection15:
	BTFSC      STATUS+0, 2
	GOTO       L__MGPIO_vSetPinDirection16
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__MGPIO_vSetPinDirection15
L__MGPIO_vSetPinDirection16:
	MOVF       R0+0, 0
	IORWF      TRISD+0, 1
	GOTO       L_MGPIO_vSetPinDirection6
L_MGPIO_vSetPinDirection5:
;GPIO.c,11 :: 		else CLR_BIT(TRISD, Copy_u8Pin);
	MOVF       FARG_MGPIO_vSetPinDirection_Copy_u8Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__MGPIO_vSetPinDirection17:
	BTFSC      STATUS+0, 2
	GOTO       L__MGPIO_vSetPinDirection18
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__MGPIO_vSetPinDirection17
L__MGPIO_vSetPinDirection18:
	COMF       R0+0, 1
	MOVF       R0+0, 0
	ANDWF      TRISD+0, 1
L_MGPIO_vSetPinDirection6:
;GPIO.c,12 :: 		}
L_MGPIO_vSetPinDirection4:
L_MGPIO_vSetPinDirection3:
;GPIO.c,13 :: 		}
L_end_MGPIO_vSetPinDirection:
	RETURN
; end of _MGPIO_vSetPinDirection

_MGPIO_vTogglePin:

;GPIO.c,15 :: 		void MGPIO_vTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin) {
;GPIO.c,16 :: 		if (Copy_u8Port == PORTB_ID) TOG_BIT(PORTB, Copy_u8Pin);
	MOVF       FARG_MGPIO_vTogglePin_Copy_u8Port+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_MGPIO_vTogglePin7
	MOVF       FARG_MGPIO_vTogglePin_Copy_u8Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__MGPIO_vTogglePin20:
	BTFSC      STATUS+0, 2
	GOTO       L__MGPIO_vTogglePin21
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__MGPIO_vTogglePin20
L__MGPIO_vTogglePin21:
	MOVF       R0+0, 0
	XORWF      PORTB+0, 1
	GOTO       L_MGPIO_vTogglePin8
L_MGPIO_vTogglePin7:
;GPIO.c,17 :: 		else if (Copy_u8Port == PORTD_ID) TOG_BIT(PORTD, Copy_u8Pin);
	MOVF       FARG_MGPIO_vTogglePin_Copy_u8Port+0, 0
	XORLW      3
	BTFSS      STATUS+0, 2
	GOTO       L_MGPIO_vTogglePin9
	MOVF       FARG_MGPIO_vTogglePin_Copy_u8Pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__MGPIO_vTogglePin22:
	BTFSC      STATUS+0, 2
	GOTO       L__MGPIO_vTogglePin23
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__MGPIO_vTogglePin22
L__MGPIO_vTogglePin23:
	MOVF       R0+0, 0
	XORWF      PORTD+0, 1
L_MGPIO_vTogglePin9:
L_MGPIO_vTogglePin8:
;GPIO.c,18 :: 		}
L_end_MGPIO_vTogglePin:
	RETURN
; end of _MGPIO_vTogglePin
