
_I2C_Test:

;i2c_test.c,4 :: 		void I2C_Test(void)
;i2c_test.c,6 :: 		I2C_Init();
	CALL       _I2C_Init+0
;i2c_test.c,8 :: 		I2C_Start();
	CALL       _I2C_Start+0
;i2c_test.c,9 :: 		I2C_Write(0xA0); // Example: send device address
	MOVLW      160
	MOVWF      FARG_I2C_Write_d+0
	CALL       _I2C_Write+0
;i2c_test.c,10 :: 		I2C_Write(0x00); // Example: send memory address
	CLRF       FARG_I2C_Write_d+0
	CALL       _I2C_Write+0
;i2c_test.c,11 :: 		I2C_Stop();
	CALL       _I2C_Stop+0
;i2c_test.c,12 :: 		}
L_end_I2C_Test:
	RETURN
; end of _I2C_Test
