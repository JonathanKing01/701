################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../YCrCb.c 

OBJS += \
./YCrCb.o 

C_DEPS += \
./YCrCb.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\LegUp-7.0\legup\/legup-library/" -I"C:\LegUp-7.0\legup\/../cygwin64/lib/gcc/x86_64-pc-cygwin/5.4.0/include" -I"C:\LegUp-7.0\legup\/../cygwin64/usr/include" -I"C:\LegUp-7.0\legup\/../cygwin64/usr/include/w32api" -O0 -g3 -pg -Wall -c -fmessage-length=0 -Wno-unused-label -Wno-unknown-pragmas -Wno-attributes -Werror=implicit-function-declaration -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


