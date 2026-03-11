
_App_Timer0_Action:

;main.c,11 :: 		void App_Timer0_Action(void) {
;main.c,12 :: 		TimerCounter++;
	MOVF       _TimerCounter+0, 0
	ADDLW      1
	MOVWF      R0+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _TimerCounter+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      _TimerCounter+0
	MOVF       R0+1, 0
	MOVWF      _TimerCounter+1
;main.c,15 :: 		if (TimerCounter % 1000 == 0) {
	MOVLW      232
	MOVWF      R4+0
	MOVLW      3
	MOVWF      R4+1
	MOVF       _TimerCounter+0, 0
	MOVWF      R0+0
	MOVF       _TimerCounter+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVLW      0
	XORWF      R0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__App_Timer0_Action10
	MOVLW      0
	XORWF      R0+0, 0
L__App_Timer0_Action10:
	BTFSS      STATUS+0, 2
	GOTO       L_App_Timer0_Action0
;main.c,16 :: 		if (Led2_State == 0) {
	MOVF       main_Led2_State+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_App_Timer0_Action1
;main.c,17 :: 		LED_On(GPIO_PORTB, GPIO_PIN2);
	MOVLW      1
	MOVWF      FARG_LED_On_Port+0
	MOVLW      2
	MOVWF      FARG_LED_On_Pin+0
	CALL       _LED_On+0
;main.c,18 :: 		Led2_State = 1;
	MOVLW      1
	MOVWF      main_Led2_State+0
;main.c,19 :: 		}
	GOTO       L_App_Timer0_Action2
L_App_Timer0_Action1:
;main.c,21 :: 		LED_Off(GPIO_PORTB, GPIO_PIN2);
	MOVLW      1
	MOVWF      FARG_LED_Off_Port+0
	MOVLW      2
	MOVWF      FARG_LED_Off_Pin+0
	CALL       _LED_Off+0
;main.c,22 :: 		Led2_State = 0;
	CLRF       main_Led2_State+0
;main.c,23 :: 		}
L_App_Timer0_Action2:
;main.c,24 :: 		}
L_App_Timer0_Action0:
;main.c,27 :: 		if (TimerCounter % 2000 == 0) {
	MOVLW      208
	MOVWF      R4+0
	MOVLW      7
	MOVWF      R4+1
	MOVF       _TimerCounter+0, 0
	MOVWF      R0+0
	MOVF       _TimerCounter+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVLW      0
	XORWF      R0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__App_Timer0_Action11
	MOVLW      0
	XORWF      R0+0, 0
L__App_Timer0_Action11:
	BTFSS      STATUS+0, 2
	GOTO       L_App_Timer0_Action3
;main.c,28 :: 		if (Led1_State == 0) {
	MOVF       main_Led1_State+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_App_Timer0_Action4
;main.c,29 :: 		LED_On(GPIO_PORTB, GPIO_PIN1);
	MOVLW      1
	MOVWF      FARG_LED_On_Port+0
	MOVLW      1
	MOVWF      FARG_LED_On_Pin+0
	CALL       _LED_On+0
;main.c,30 :: 		Led1_State = 1;
	MOVLW      1
	MOVWF      main_Led1_State+0
;main.c,31 :: 		}
	GOTO       L_App_Timer0_Action5
L_App_Timer0_Action4:
;main.c,33 :: 		LED_Off(GPIO_PORTB, GPIO_PIN1);
	MOVLW      1
	MOVWF      FARG_LED_Off_Port+0
	MOVLW      1
	MOVWF      FARG_LED_Off_Pin+0
	CALL       _LED_Off+0
;main.c,34 :: 		Led1_State = 0;
	CLRF       main_Led1_State+0
;main.c,35 :: 		}
L_App_Timer0_Action5:
;main.c,36 :: 		}
L_App_Timer0_Action3:
;main.c,38 :: 		if (TimerCounter == 2000) {
	MOVF       _TimerCounter+1, 0
	XORLW      7
	BTFSS      STATUS+0, 2
	GOTO       L__App_Timer0_Action12
	MOVLW      208
	XORWF      _TimerCounter+0, 0
L__App_Timer0_Action12:
	BTFSS      STATUS+0, 2
	GOTO       L_App_Timer0_Action6
;main.c,39 :: 		TimerCounter = 0;
	CLRF       _TimerCounter+0
	CLRF       _TimerCounter+1
;main.c,40 :: 		}
L_App_Timer0_Action6:
;main.c,41 :: 		}
L_end_App_Timer0_Action:
	RETURN
; end of _App_Timer0_Action

_main:

;main.c,43 :: 		void main() {
;main.c,45 :: 		LED_Init(GPIO_PORTB, GPIO_PIN1);
	MOVLW      1
	MOVWF      FARG_LED_Init_Port+0
	MOVLW      1
	MOVWF      FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;main.c,46 :: 		LED_Init(GPIO_PORTB, GPIO_PIN2);
	MOVLW      1
	MOVWF      FARG_LED_Init_Port+0
	MOVLW      2
	MOVWF      FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;main.c,47 :: 		TIMER0_voidInit();
	CALL       _TIMER0_voidInit+0
;main.c,48 :: 		TIMER0_voidSetPreload(6);
	MOVLW      6
	MOVWF      FARG_TIMER0_voidSetPreload_Copy_u8Preload+0
	CALL       _TIMER0_voidSetPreload+0
;main.c,49 :: 		TIMER0_voidSetCallBack(App_Timer0_Action);
	MOVLW      _App_Timer0_Action+0
	MOVWF      FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+0
	MOVLW      hi_addr(_App_Timer0_Action+0)
	MOVWF      FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+1
	MOVLW      0
	MOVWF      FARG_TIMER0_voidSetCallBack_Copy_ptrToFunc+2
	MOVLW      0
	CALL       _TIMER0_voidSetCallBack+0
;main.c,50 :: 		TIMER0_voidEnableInterrupt();
	CALL       _TIMER0_voidEnableInterrupt+0
;main.c,51 :: 		GIE_voidEnable();
	CALL       _GIE_voidEnable+0
;main.c,52 :: 		while (1) {
L_main7:
;main.c,54 :: 		}
	GOTO       L_main7
;main.c,55 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
