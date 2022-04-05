################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/simd-support/altivec.c \
../Core/Src/fftw-3.3.10/simd-support/avx-128-fma.c \
../Core/Src/fftw-3.3.10/simd-support/avx.c \
../Core/Src/fftw-3.3.10/simd-support/avx2.c \
../Core/Src/fftw-3.3.10/simd-support/avx512.c \
../Core/Src/fftw-3.3.10/simd-support/kcvi.c \
../Core/Src/fftw-3.3.10/simd-support/neon.c \
../Core/Src/fftw-3.3.10/simd-support/sse2.c \
../Core/Src/fftw-3.3.10/simd-support/taint.c \
../Core/Src/fftw-3.3.10/simd-support/vsx.c 

OBJS += \
./Core/Src/fftw-3.3.10/simd-support/altivec.o \
./Core/Src/fftw-3.3.10/simd-support/avx-128-fma.o \
./Core/Src/fftw-3.3.10/simd-support/avx.o \
./Core/Src/fftw-3.3.10/simd-support/avx2.o \
./Core/Src/fftw-3.3.10/simd-support/avx512.o \
./Core/Src/fftw-3.3.10/simd-support/kcvi.o \
./Core/Src/fftw-3.3.10/simd-support/neon.o \
./Core/Src/fftw-3.3.10/simd-support/sse2.o \
./Core/Src/fftw-3.3.10/simd-support/taint.o \
./Core/Src/fftw-3.3.10/simd-support/vsx.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/simd-support/altivec.d \
./Core/Src/fftw-3.3.10/simd-support/avx-128-fma.d \
./Core/Src/fftw-3.3.10/simd-support/avx.d \
./Core/Src/fftw-3.3.10/simd-support/avx2.d \
./Core/Src/fftw-3.3.10/simd-support/avx512.d \
./Core/Src/fftw-3.3.10/simd-support/kcvi.d \
./Core/Src/fftw-3.3.10/simd-support/neon.d \
./Core/Src/fftw-3.3.10/simd-support/sse2.d \
./Core/Src/fftw-3.3.10/simd-support/taint.d \
./Core/Src/fftw-3.3.10/simd-support/vsx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/simd-support/%.o: ../Core/Src/fftw-3.3.10/simd-support/%.c Core/Src/fftw-3.3.10/simd-support/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-simd-2d-support

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-simd-2d-support:
	-$(RM) ./Core/Src/fftw-3.3.10/simd-support/altivec.d ./Core/Src/fftw-3.3.10/simd-support/altivec.o ./Core/Src/fftw-3.3.10/simd-support/avx-128-fma.d ./Core/Src/fftw-3.3.10/simd-support/avx-128-fma.o ./Core/Src/fftw-3.3.10/simd-support/avx.d ./Core/Src/fftw-3.3.10/simd-support/avx.o ./Core/Src/fftw-3.3.10/simd-support/avx2.d ./Core/Src/fftw-3.3.10/simd-support/avx2.o ./Core/Src/fftw-3.3.10/simd-support/avx512.d ./Core/Src/fftw-3.3.10/simd-support/avx512.o ./Core/Src/fftw-3.3.10/simd-support/kcvi.d ./Core/Src/fftw-3.3.10/simd-support/kcvi.o ./Core/Src/fftw-3.3.10/simd-support/neon.d ./Core/Src/fftw-3.3.10/simd-support/neon.o ./Core/Src/fftw-3.3.10/simd-support/sse2.d ./Core/Src/fftw-3.3.10/simd-support/sse2.o ./Core/Src/fftw-3.3.10/simd-support/taint.d ./Core/Src/fftw-3.3.10/simd-support/taint.o ./Core/Src/fftw-3.3.10/simd-support/vsx.d ./Core/Src/fftw-3.3.10/simd-support/vsx.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-simd-2d-support

