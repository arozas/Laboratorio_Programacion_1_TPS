################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/eFlight.c \
../src/ePassenger.c \
../src/input.c \
../src/menu.c \
../src/operations.c \
../src/trabajo_practico_2.c \
../src/uReports.c 

C_DEPS += \
./src/eFlight.d \
./src/ePassenger.d \
./src/input.d \
./src/menu.d \
./src/operations.d \
./src/trabajo_practico_2.d \
./src/uReports.d 

OBJS += \
./src/eFlight.o \
./src/ePassenger.o \
./src/input.o \
./src/menu.o \
./src/operations.o \
./src/trabajo_practico_2.o \
./src/uReports.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/eFlight.d ./src/eFlight.o ./src/ePassenger.d ./src/ePassenger.o ./src/input.d ./src/input.o ./src/menu.d ./src/menu.o ./src/operations.d ./src/operations.o ./src/trabajo_practico_2.d ./src/trabajo_practico_2.o ./src/uReports.d ./src/uReports.o

.PHONY: clean-src

