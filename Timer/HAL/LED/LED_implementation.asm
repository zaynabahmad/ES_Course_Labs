
_LED_Init:

;LED_implementation.c,4 :: 		void LED_Init(u8 port, u8 pin) {
;LED_implementation.c,5 :: 		set_pin_direction(port, pin, OUTPUT);
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_set_pin_direction_port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_set_pin_direction_pin+0
	CLRF       FARG_set_pin_direction_direction+0
	CALL       _set_pin_direction+0
;LED_implementation.c,6 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_ON:

;LED_implementation.c,8 :: 		void LED_ON(u8 port, u8 pin) {
;LED_implementation.c,9 :: 		set_pin_value(port, pin, HIGH);
	MOVF       FARG_LED_ON_port+0, 0
	MOVWF      FARG_set_pin_value_port+0
	MOVF       FARG_LED_ON_pin+0, 0
	MOVWF      FARG_set_pin_value_pin+0
	MOVLW      1
	MOVWF      FARG_set_pin_value_value+0
	CALL       _set_pin_value+0
;LED_implementation.c,10 :: 		}
L_end_LED_ON:
	RETURN
; end of _LED_ON

_LED_OFF:

;LED_implementation.c,12 :: 		void LED_OFF(u8 port, u8 pin) {
;LED_implementation.c,13 :: 		set_pin_value(port, pin, LOW);
	MOVF       FARG_LED_OFF_port+0, 0
	MOVWF      FARG_set_pin_value_port+0
	MOVF       FARG_LED_OFF_pin+0, 0
	MOVWF      FARG_set_pin_value_pin+0
	CLRF       FARG_set_pin_value_value+0
	CALL       _set_pin_value+0
;LED_implementation.c,14 :: 		}
L_end_LED_OFF:
	RETURN
; end of _LED_OFF

_LED_Toggle:

;LED_implementation.c,15 :: 		void LED_Toggle(u8 port, u8 pin) {
;LED_implementation.c,16 :: 		toggle_pin(port, pin);
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_toggle_pin_port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_toggle_pin_pin+0
	CALL       _toggle_pin+0
;LED_implementation.c,17 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
