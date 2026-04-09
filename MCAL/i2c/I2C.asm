
_I2C_Master_Init:

;I2C.c,6 :: 		void I2C_Master_Init(u32 Clock) {
;I2C.c,8 :: 		GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	CLRF       FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;I2C.c,9 :: 		GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_INPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Port+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_Direction+0
	CALL       _GPIO_SetPinDirection+0
;I2C.c,12 :: 		SSPCON = 0x28;
	MOVLW      40
	MOVWF      20
;I2C.c,15 :: 		SSPADD = (u8)((4000000 / (4 * Clock)) - 1);
	MOVF       FARG_I2C_Master_Init_Clock+0, 0
	MOVWF      R4+0
	MOVF       FARG_I2C_Master_Init_Clock+1, 0
	MOVWF      R4+1
	MOVF       FARG_I2C_Master_Init_Clock+2, 0
	MOVWF      R4+2
	MOVF       FARG_I2C_Master_Init_Clock+3, 0
	MOVWF      R4+3
	RLF        R4+0, 1
	RLF        R4+1, 1
	RLF        R4+2, 1
	RLF        R4+3, 1
	BCF        R4+0, 0
	RLF        R4+0, 1
	RLF        R4+1, 1
	RLF        R4+2, 1
	RLF        R4+3, 1
	BCF        R4+0, 0
	MOVLW      0
	MOVWF      R0+0
	MOVLW      9
	MOVWF      R0+1
	MOVLW      61
	MOVWF      R0+2
	MOVLW      0
	MOVWF      R0+3
	CALL       _Div_32x32_U+0
	DECF       R0+0, 0
	MOVWF      147
;I2C.c,18 :: 		SSPSTAT = 0x80;
	MOVLW      128
	MOVWF      148
;I2C.c,19 :: 		}
L_end_I2C_Master_Init:
	RETURN
; end of _I2C_Master_Init

_I2C_Master_Wait:

;I2C.c,21 :: 		void I2C_Master_Wait(void) {
;I2C.c,23 :: 		while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
L_I2C_Master_Wait0:
	BTFSC      148, 2
	GOTO       L__I2C_Master_Wait6
	MOVLW      31
	ANDWF      145, 0
	MOVWF      R0+0
	BTFSS      STATUS+0, 2
	GOTO       L__I2C_Master_Wait6
	GOTO       L_I2C_Master_Wait1
L__I2C_Master_Wait6:
	GOTO       L_I2C_Master_Wait0
L_I2C_Master_Wait1:
;I2C.c,24 :: 		}
L_end_I2C_Master_Wait:
	RETURN
; end of _I2C_Master_Wait

_I2C_Master_Start:

;I2C.c,26 :: 		void I2C_Master_Start(void) {
;I2C.c,27 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,28 :: 		SET_BIT(SSPCON2, SEN);
	BSF        145, 0
;I2C.c,29 :: 		}
L_end_I2C_Master_Start:
	RETURN
; end of _I2C_Master_Start

_I2C_Master_RepeatedStart:

;I2C.c,31 :: 		void I2C_Master_RepeatedStart(void) {
;I2C.c,32 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,33 :: 		SET_BIT(SSPCON2, RSEN);
	BSF        145, 1
;I2C.c,34 :: 		}
L_end_I2C_Master_RepeatedStart:
	RETURN
; end of _I2C_Master_RepeatedStart

_I2C_Master_Stop:

;I2C.c,36 :: 		void I2C_Master_Stop(void) {
;I2C.c,37 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,38 :: 		SET_BIT(SSPCON2, PEN);
	BSF        145, 2
;I2C.c,39 :: 		}
L_end_I2C_Master_Stop:
	RETURN
; end of _I2C_Master_Stop

_I2C_Master_Write:

;I2C.c,41 :: 		void I2C_Master_Write(u8 Data) {
;I2C.c,42 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,43 :: 		SSPBUF = Data;
	MOVF       FARG_I2C_Master_Write_Data+0, 0
	MOVWF      19
;I2C.c,44 :: 		}
L_end_I2C_Master_Write:
	RETURN
; end of _I2C_Master_Write

_I2C_Master_Read:

;I2C.c,46 :: 		u8 I2C_Master_Read(u8 Ack) {
;I2C.c,48 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,50 :: 		SET_BIT(SSPCON2, RCEN);
	BSF        145, 3
;I2C.c,52 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,53 :: 		local_data = SSPBUF;
	MOVF       19, 0
	MOVWF      I2C_Master_Read_local_data_L0+0
;I2C.c,55 :: 		I2C_Master_Wait();
	CALL       _I2C_Master_Wait+0
;I2C.c,57 :: 		if(Ack) CLR_BIT(SSPCON2, ACKDT);
	MOVF       FARG_I2C_Master_Read_Ack+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_I2C_Master_Read4
	MOVLW      223
	ANDWF      145, 1
	GOTO       L_I2C_Master_Read5
L_I2C_Master_Read4:
;I2C.c,58 :: 		else    SET_BIT(SSPCON2, ACKDT);
	BSF        145, 5
L_I2C_Master_Read5:
;I2C.c,60 :: 		SET_BIT(SSPCON2, ACKEN);
	BSF        145, 4
;I2C.c,62 :: 		return local_data;
	MOVF       I2C_Master_Read_local_data_L0+0, 0
	MOVWF      R0+0
;I2C.c,63 :: 		}
L_end_I2C_Master_Read:
	RETURN
; end of _I2C_Master_Read
