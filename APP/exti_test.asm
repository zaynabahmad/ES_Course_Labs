
_EXTI_Test:

;exti_test.c,5 :: 		void EXTI_Test(void)
;exti_test.c,7 :: 		GPIO_SetPinDirection(PORTB, PIN0, OUTPUT); // LED
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	CLRF       FARG_GPIO_SetPinDirection_pin+0
	CLRF       FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;exti_test.c,8 :: 		GPIO_SetPinDirection(PORTB, PIN0, INPUT);  // INT pin (RB0)
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	CLRF       FARG_GPIO_SetPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;exti_test.c,10 :: 		EXTI_Init(RISING_EDGE);
	MOVLW      1
	MOVWF      FARG_EXTI_Init_edge+0
	CALL       _EXTI_Init+0
;exti_test.c,11 :: 		EXTI_Enable();
	CALL       _EXTI_Enable+0
;exti_test.c,13 :: 		while(1)
L_EXTI_Test0:
;exti_test.c,16 :: 		}
	GOTO       L_EXTI_Test0
;exti_test.c,17 :: 		}
L_end_EXTI_Test:
	RETURN
; end of _EXTI_Test
