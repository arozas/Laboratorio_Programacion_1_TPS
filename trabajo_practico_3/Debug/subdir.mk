################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Flight.c \
../Passenger.c \
../input.c \
../main.c \
../menu.c \
../operations.c \
../parser.c 

C_DEPS += \
./Controller.d \
./Flight.d \
./Passenger.d \
./input.d \
./main.d \
./menu.d \
./operations.d \
./parser.d 

OBJS += \
./Controller.o \
./Flight.o \
./Passenger.o \
./input.o \
./main.o \
./menu.o \
./operations.o \
./parser.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Controller.d ./Controller.o ./Flight.d ./Flight.o ./Passenger.d ./Passenger.o ./input.d ./input.o ./main.d ./main.o ./menu.d ./menu.o ./operations.d ./operations.o ./parser.d ./parser.o

.PHONY: clean--2e-

