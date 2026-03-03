
_HLED_vInit:

;LED.c,7 :: 		void HLED_vInit(void) {
;LED.c,8 :: 		MGPIO_vSetPinDirection(LED_PORT_ID, LED_PIN_ID, PIN_OUTPUT);
	MOVLW      3
	MOVWF      FARG_MGPIO_vSetPinDirection_Copy_u8Port+0
	CLRF       FARG_MGPIO_vSetPinDirection_Copy_u8Pin+0
	CLRF       FARG_MGPIO_vSetPinDirection_Copy_u8Direction+0
	CALL       _MGPIO_vSetPinDirection+0
;LED.c,9 :: 		}
L_end_HLED_vInit:
	RETURN
; end of _HLED_vInit

_HLED_vToggle:

;LED.c,11 :: 		void HLED_vToggle(void) {
;LED.c,12 :: 		MGPIO_vTogglePin(LED_PORT_ID, LED_PIN_ID);
	MOVLW      3
	MOVWF      FARG_MGPIO_vTogglePin_Copy_u8Port+0
	CLRF       FARG_MGPIO_vTogglePin_Copy_u8Pin+0
	CALL       _MGPIO_vTogglePin+0
;LED.c,13 :: 		}
L_end_HLED_vToggle:
	RETURN
; end of _HLED_vToggle
