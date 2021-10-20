################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC\ Motor/DC_Motor.c 

OBJS += \
./DC\ Motor/DC_Motor.o 

C_DEPS += \
./DC\ Motor/DC_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
DC\ Motor/DC_Motor.o: ../DC\ Motor/DC_Motor.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"DC Motor/DC_Motor.d" -MT"DC\ Motor/DC_Motor.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


