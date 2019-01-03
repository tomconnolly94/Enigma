################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/plugboard/plugboard.cpp 

OBJS += \
./src/plugboard/plugboard.o 

CPP_DEPS += \
./src/plugboard/plugboard.d 


# Each subdirectory must supply rules for building sources it contributes
src/plugboard/%.o: ../src/plugboard/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


