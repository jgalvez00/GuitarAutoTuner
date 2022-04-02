################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/support/addchain.c 

OBJS += \
./Core/Src/fftw-3.3.10/support/addchain.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/support/addchain.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/support/%.o: ../Core/Src/fftw-3.3.10/support/%.c Core/Src/fftw-3.3.10/support/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-support

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-support:
	-$(RM) ./Core/Src/fftw-3.3.10/support/addchain.d ./Core/Src/fftw-3.3.10/support/addchain.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-support

