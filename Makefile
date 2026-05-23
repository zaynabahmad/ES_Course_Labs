# MCU
MCU = 16f877a

# Compiler
CC = xc8-cc

# DFP
DFP = C:\Maro\ZC\Embedded\xc8\xc8\
#DFP = /opt/microchip/PIC16Fxxx_DFP/1.7.162/xc8

# Target
TARGET = app

# Source files
SRCS = \
APP/main.c \
HAL/BUZZER/BUZZER.c \
HAL/DOOR_SENSOR/DOOR_SENSOR.c \
MCAL/GPIO/GPIO.c \
MCAL/ADC/ADC.c \
MCAL/USART/USART.c \
MCAL/TIMER_0/TIMER_0.c \
MCAL/TIMER_1/TIMER_1.c \
MCAL/I2C/I2C.c \
MCAL/PWM/PWM.c \
MCAL/EXT_INT/EXT_INT.c \
MCAL/INTERRUPT_MANAGER/Interrupt_Manager.c

# Include directories
INCLUDES = \
-IAPP \
-IHAL/BUZZER \
-IHAL/DOOR_SENSOR \
-IMCAL/GPIO \
-IMCAL/ADC \
-IMCAL/USART \
-IMCAL/TIMER_0 \
-IMCAL/TIMER_1 \
-IMCAL/I2C \
-IMCAL/PWM \
-IMCAL/EXT_INT \
-IMCAL/INTERRUPT_MANAGER \
-ISERVICES

# Flags
CFLAGS = -mcpu=$(MCU) -mdfp=$(DFP) $(INCLUDES) -Wall -Wextra

# Default target
all: $(TARGET).hex

# Build target
$(TARGET).hex: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).hex $(SRCS)

flash: $(TARGET).hex
	picpro program -p /dev/ttyUSB0 -i $(TARGET).hex -t $(MCU)

# Clean
clean:
	rm -f *.hex *.elf *.o *.d *.map *.lst *.cmf *.hxl *.p1 *.rlf *.s *.sdb *.sym

.PHONY: all flash clean
