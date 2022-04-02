################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/rdft/scalar/hc2c.c \
../Core/Src/fftw-3.3.10/rdft/scalar/hfb.c \
../Core/Src/fftw-3.3.10/rdft/scalar/r2c.c \
../Core/Src/fftw-3.3.10/rdft/scalar/r2r.c 

OBJS += \
./Core/Src/fftw-3.3.10/rdft/scalar/hc2c.o \
./Core/Src/fftw-3.3.10/rdft/scalar/hfb.o \
./Core/Src/fftw-3.3.10/rdft/scalar/r2c.o \
./Core/Src/fftw-3.3.10/rdft/scalar/r2r.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/rdft/scalar/hc2c.d \
./Core/Src/fftw-3.3.10/rdft/scalar/hfb.d \
./Core/Src/fftw-3.3.10/rdft/scalar/r2c.d \
./Core/Src/fftw-3.3.10/rdft/scalar/r2r.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/rdft/scalar/%.o: ../Core/Src/fftw-3.3.10/rdft/scalar/%.c Core/Src/fftw-3.3.10/rdft/scalar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-rdft-2f-scalar

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-rdft-2f-scalar:
	-$(RM) ./Core/Src/fftw-3.3.10/rdft/scalar/hc2c.d ./Core/Src/fftw-3.3.10/rdft/scalar/hc2c.o ./Core/Src/fftw-3.3.10/rdft/scalar/hfb.d ./Core/Src/fftw-3.3.10/rdft/scalar/hfb.o ./Core/Src/fftw-3.3.10/rdft/scalar/r2c.d ./Core/Src/fftw-3.3.10/rdft/scalar/r2c.o ./Core/Src/fftw-3.3.10/rdft/scalar/r2r.d ./Core/Src/fftw-3.3.10/rdft/scalar/r2r.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-rdft-2f-scalar

