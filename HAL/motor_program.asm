
_MOTOR_Init:

;motor_program.c,5 :: 		void MOTOR_Init(u8 port1, u8 pin1, u8 port2, u8 pin2)
;motor_program.c,7 :: 		GPIO_setPinDirection(port1, pin1, GPIO_OUTPUT);
	MOVF       FARG_MOTOR_Init_port1+0, 0
	MOVWF      FARG_GPIO_setPinDirection_port+0
	MOVF       FARG_MOTOR_Init_pin1+0, 0
	MOVWF      FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;motor_program.c,8 :: 		GPIO_setPinDirection(port2, pin2, GPIO_OUTPUT);
	MOVF       FARG_MOTOR_Init_port2+0, 0
	MOVWF      FARG_GPIO_setPinDirection_port+0
	MOVF       FARG_MOTOR_Init_pin2+0, 0
	MOVWF      FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;motor_program.c,10 :: 		GPIO_setPinValue(port1, pin1, GPIO_LOW);
	MOVF       FARG_MOTOR_Init_port1+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Init_pin1+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,11 :: 		GPIO_setPinValue(port2, pin2, GPIO_LOW);
	MOVF       FARG_MOTOR_Init_port2+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Init_pin2+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,12 :: 		}
L_end_MOTOR_Init:
	RETURN
; end of _MOTOR_Init

_MOTOR_Forward:

;motor_program.c,14 :: 		void MOTOR_Forward(u8 port1, u8 pin1, u8 port2, u8 pin2)
;motor_program.c,16 :: 		GPIO_setPinValue(port1, pin1, GPIO_HIGH);
	MOVF       FARG_MOTOR_Forward_port1+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Forward_pin1+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,17 :: 		GPIO_setPinValue(port2, pin2, GPIO_LOW);
	MOVF       FARG_MOTOR_Forward_port2+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Forward_pin2+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,18 :: 		}
L_end_MOTOR_Forward:
	RETURN
; end of _MOTOR_Forward

_MOTOR_Reverse:

;motor_program.c,20 :: 		void MOTOR_Reverse(u8 port1, u8 pin1, u8 port2, u8 pin2)
;motor_program.c,22 :: 		GPIO_setPinValue(port1, pin1, GPIO_LOW);
	MOVF       FARG_MOTOR_Reverse_port1+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Reverse_pin1+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,23 :: 		GPIO_setPinValue(port2, pin2, GPIO_HIGH);
	MOVF       FARG_MOTOR_Reverse_port2+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Reverse_pin2+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,24 :: 		}
L_end_MOTOR_Reverse:
	RETURN
; end of _MOTOR_Reverse

_MOTOR_Stop:

;motor_program.c,26 :: 		void MOTOR_Stop(u8 port1, u8 pin1, u8 port2, u8 pin2)
;motor_program.c,28 :: 		GPIO_setPinValue(port1, pin1, GPIO_LOW);
	MOVF       FARG_MOTOR_Stop_port1+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Stop_pin1+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,29 :: 		GPIO_setPinValue(port2, pin2, GPIO_LOW);
	MOVF       FARG_MOTOR_Stop_port2+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_MOTOR_Stop_pin2+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;motor_program.c,30 :: 		}
L_end_MOTOR_Stop:
	RETURN
; end of _MOTOR_Stop
