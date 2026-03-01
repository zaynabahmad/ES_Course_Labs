
_LED_Init:

;LED.c,4 :: 		void LED_Init(unsigned char port, unsigned char pin){
;LED.c,5 :: 		GPIO_SetPinDirection(port, pin, GPIO_OUTPUT);
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;LED.c,6 :: 		GPIO_SetPinValue(port, pin, GPIO_LOW);
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
;LED.c,7 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_Toggle:

;LED.c,9 :: 		void LED_Toggle(unsigned char port, unsigned char pin){
;LED.c,10 :: 		if(GPIO_GetPinValue(port, pin))
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_GPIO_GetPinValue_Port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_GPIO_GetPinValue_Pin+0
	CALL       _GPIO_GetPinValue+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_LED_Toggle0
;LED.c,11 :: 		GPIO_SetPinValue(port, pin, GPIO_LOW);
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	CLRF       FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
	GOTO       L_LED_Toggle1
L_LED_Toggle0:
;LED.c,13 :: 		GPIO_SetPinValue(port, pin, GPIO_HIGH);
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_GPIO_SetPinValue_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinValue_Value+0
	CALL       _GPIO_SetPinValue+0
L_LED_Toggle1:
;LED.c,14 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
