################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/rdft/buffered.c \
../Core/Src/fftw-3.3.10/rdft/buffered2.c \
../Core/Src/fftw-3.3.10/rdft/conf.c \
../Core/Src/fftw-3.3.10/rdft/ct-hc2c-direct.c \
../Core/Src/fftw-3.3.10/rdft/ct-hc2c.c \
../Core/Src/fftw-3.3.10/rdft/dft-r2hc.c \
../Core/Src/fftw-3.3.10/rdft/dht-r2hc.c \
../Core/Src/fftw-3.3.10/rdft/dht-rader.c \
../Core/Src/fftw-3.3.10/rdft/direct-r2c.c \
../Core/Src/fftw-3.3.10/rdft/direct-r2r.c \
../Core/Src/fftw-3.3.10/rdft/direct2.c \
../Core/Src/fftw-3.3.10/rdft/generic.c \
../Core/Src/fftw-3.3.10/rdft/hc2hc-direct.c \
../Core/Src/fftw-3.3.10/rdft/hc2hc-generic.c \
../Core/Src/fftw-3.3.10/rdft/hc2hc.c \
../Core/Src/fftw-3.3.10/rdft/indirect.c \
../Core/Src/fftw-3.3.10/rdft/khc2c.c \
../Core/Src/fftw-3.3.10/rdft/khc2hc.c \
../Core/Src/fftw-3.3.10/rdft/kr2c.c \
../Core/Src/fftw-3.3.10/rdft/kr2r.c \
../Core/Src/fftw-3.3.10/rdft/nop.c \
../Core/Src/fftw-3.3.10/rdft/nop2.c \
../Core/Src/fftw-3.3.10/rdft/plan.c \
../Core/Src/fftw-3.3.10/rdft/plan2.c \
../Core/Src/fftw-3.3.10/rdft/problem.c \
../Core/Src/fftw-3.3.10/rdft/problem2.c \
../Core/Src/fftw-3.3.10/rdft/rank-geq2-rdft2.c \
../Core/Src/fftw-3.3.10/rdft/rank-geq2.c \
../Core/Src/fftw-3.3.10/rdft/rank0-rdft2.c \
../Core/Src/fftw-3.3.10/rdft/rank0.c \
../Core/Src/fftw-3.3.10/rdft/rdft-dht.c \
../Core/Src/fftw-3.3.10/rdft/rdft2-inplace-strides.c \
../Core/Src/fftw-3.3.10/rdft/rdft2-rdft.c \
../Core/Src/fftw-3.3.10/rdft/rdft2-strides.c \
../Core/Src/fftw-3.3.10/rdft/rdft2-tensor-max-index.c \
../Core/Src/fftw-3.3.10/rdft/solve.c \
../Core/Src/fftw-3.3.10/rdft/solve2.c \
../Core/Src/fftw-3.3.10/rdft/vrank-geq1-rdft2.c \
../Core/Src/fftw-3.3.10/rdft/vrank-geq1.c \
../Core/Src/fftw-3.3.10/rdft/vrank3-transpose.c 

OBJS += \
./Core/Src/fftw-3.3.10/rdft/buffered.o \
./Core/Src/fftw-3.3.10/rdft/buffered2.o \
./Core/Src/fftw-3.3.10/rdft/conf.o \
./Core/Src/fftw-3.3.10/rdft/ct-hc2c-direct.o \
./Core/Src/fftw-3.3.10/rdft/ct-hc2c.o \
./Core/Src/fftw-3.3.10/rdft/dft-r2hc.o \
./Core/Src/fftw-3.3.10/rdft/dht-r2hc.o \
./Core/Src/fftw-3.3.10/rdft/dht-rader.o \
./Core/Src/fftw-3.3.10/rdft/direct-r2c.o \
./Core/Src/fftw-3.3.10/rdft/direct-r2r.o \
./Core/Src/fftw-3.3.10/rdft/direct2.o \
./Core/Src/fftw-3.3.10/rdft/generic.o \
./Core/Src/fftw-3.3.10/rdft/hc2hc-direct.o \
./Core/Src/fftw-3.3.10/rdft/hc2hc-generic.o \
./Core/Src/fftw-3.3.10/rdft/hc2hc.o \
./Core/Src/fftw-3.3.10/rdft/indirect.o \
./Core/Src/fftw-3.3.10/rdft/khc2c.o \
./Core/Src/fftw-3.3.10/rdft/khc2hc.o \
./Core/Src/fftw-3.3.10/rdft/kr2c.o \
./Core/Src/fftw-3.3.10/rdft/kr2r.o \
./Core/Src/fftw-3.3.10/rdft/nop.o \
./Core/Src/fftw-3.3.10/rdft/nop2.o \
./Core/Src/fftw-3.3.10/rdft/plan.o \
./Core/Src/fftw-3.3.10/rdft/plan2.o \
./Core/Src/fftw-3.3.10/rdft/problem.o \
./Core/Src/fftw-3.3.10/rdft/problem2.o \
./Core/Src/fftw-3.3.10/rdft/rank-geq2-rdft2.o \
./Core/Src/fftw-3.3.10/rdft/rank-geq2.o \
./Core/Src/fftw-3.3.10/rdft/rank0-rdft2.o \
./Core/Src/fftw-3.3.10/rdft/rank0.o \
./Core/Src/fftw-3.3.10/rdft/rdft-dht.o \
./Core/Src/fftw-3.3.10/rdft/rdft2-inplace-strides.o \
./Core/Src/fftw-3.3.10/rdft/rdft2-rdft.o \
./Core/Src/fftw-3.3.10/rdft/rdft2-strides.o \
./Core/Src/fftw-3.3.10/rdft/rdft2-tensor-max-index.o \
./Core/Src/fftw-3.3.10/rdft/solve.o \
./Core/Src/fftw-3.3.10/rdft/solve2.o \
./Core/Src/fftw-3.3.10/rdft/vrank-geq1-rdft2.o \
./Core/Src/fftw-3.3.10/rdft/vrank-geq1.o \
./Core/Src/fftw-3.3.10/rdft/vrank3-transpose.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/rdft/buffered.d \
./Core/Src/fftw-3.3.10/rdft/buffered2.d \
./Core/Src/fftw-3.3.10/rdft/conf.d \
./Core/Src/fftw-3.3.10/rdft/ct-hc2c-direct.d \
./Core/Src/fftw-3.3.10/rdft/ct-hc2c.d \
./Core/Src/fftw-3.3.10/rdft/dft-r2hc.d \
./Core/Src/fftw-3.3.10/rdft/dht-r2hc.d \
./Core/Src/fftw-3.3.10/rdft/dht-rader.d \
./Core/Src/fftw-3.3.10/rdft/direct-r2c.d \
./Core/Src/fftw-3.3.10/rdft/direct-r2r.d \
./Core/Src/fftw-3.3.10/rdft/direct2.d \
./Core/Src/fftw-3.3.10/rdft/generic.d \
./Core/Src/fftw-3.3.10/rdft/hc2hc-direct.d \
./Core/Src/fftw-3.3.10/rdft/hc2hc-generic.d \
./Core/Src/fftw-3.3.10/rdft/hc2hc.d \
./Core/Src/fftw-3.3.10/rdft/indirect.d \
./Core/Src/fftw-3.3.10/rdft/khc2c.d \
./Core/Src/fftw-3.3.10/rdft/khc2hc.d \
./Core/Src/fftw-3.3.10/rdft/kr2c.d \
./Core/Src/fftw-3.3.10/rdft/kr2r.d \
./Core/Src/fftw-3.3.10/rdft/nop.d \
./Core/Src/fftw-3.3.10/rdft/nop2.d \
./Core/Src/fftw-3.3.10/rdft/plan.d \
./Core/Src/fftw-3.3.10/rdft/plan2.d \
./Core/Src/fftw-3.3.10/rdft/problem.d \
./Core/Src/fftw-3.3.10/rdft/problem2.d \
./Core/Src/fftw-3.3.10/rdft/rank-geq2-rdft2.d \
./Core/Src/fftw-3.3.10/rdft/rank-geq2.d \
./Core/Src/fftw-3.3.10/rdft/rank0-rdft2.d \
./Core/Src/fftw-3.3.10/rdft/rank0.d \
./Core/Src/fftw-3.3.10/rdft/rdft-dht.d \
./Core/Src/fftw-3.3.10/rdft/rdft2-inplace-strides.d \
./Core/Src/fftw-3.3.10/rdft/rdft2-rdft.d \
./Core/Src/fftw-3.3.10/rdft/rdft2-strides.d \
./Core/Src/fftw-3.3.10/rdft/rdft2-tensor-max-index.d \
./Core/Src/fftw-3.3.10/rdft/solve.d \
./Core/Src/fftw-3.3.10/rdft/solve2.d \
./Core/Src/fftw-3.3.10/rdft/vrank-geq1-rdft2.d \
./Core/Src/fftw-3.3.10/rdft/vrank-geq1.d \
./Core/Src/fftw-3.3.10/rdft/vrank3-transpose.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/rdft/%.o: ../Core/Src/fftw-3.3.10/rdft/%.c Core/Src/fftw-3.3.10/rdft/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-rdft

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-rdft:
	-$(RM) ./Core/Src/fftw-3.3.10/rdft/buffered.d ./Core/Src/fftw-3.3.10/rdft/buffered.o ./Core/Src/fftw-3.3.10/rdft/buffered2.d ./Core/Src/fftw-3.3.10/rdft/buffered2.o ./Core/Src/fftw-3.3.10/rdft/conf.d ./Core/Src/fftw-3.3.10/rdft/conf.o ./Core/Src/fftw-3.3.10/rdft/ct-hc2c-direct.d ./Core/Src/fftw-3.3.10/rdft/ct-hc2c-direct.o ./Core/Src/fftw-3.3.10/rdft/ct-hc2c.d ./Core/Src/fftw-3.3.10/rdft/ct-hc2c.o ./Core/Src/fftw-3.3.10/rdft/dft-r2hc.d ./Core/Src/fftw-3.3.10/rdft/dft-r2hc.o ./Core/Src/fftw-3.3.10/rdft/dht-r2hc.d ./Core/Src/fftw-3.3.10/rdft/dht-r2hc.o ./Core/Src/fftw-3.3.10/rdft/dht-rader.d ./Core/Src/fftw-3.3.10/rdft/dht-rader.o ./Core/Src/fftw-3.3.10/rdft/direct-r2c.d ./Core/Src/fftw-3.3.10/rdft/direct-r2c.o ./Core/Src/fftw-3.3.10/rdft/direct-r2r.d ./Core/Src/fftw-3.3.10/rdft/direct-r2r.o ./Core/Src/fftw-3.3.10/rdft/direct2.d ./Core/Src/fftw-3.3.10/rdft/direct2.o ./Core/Src/fftw-3.3.10/rdft/generic.d ./Core/Src/fftw-3.3.10/rdft/generic.o ./Core/Src/fftw-3.3.10/rdft/hc2hc-direct.d ./Core/Src/fftw-3.3.10/rdft/hc2hc-direct.o ./Core/Src/fftw-3.3.10/rdft/hc2hc-generic.d ./Core/Src/fftw-3.3.10/rdft/hc2hc-generic.o ./Core/Src/fftw-3.3.10/rdft/hc2hc.d ./Core/Src/fftw-3.3.10/rdft/hc2hc.o ./Core/Src/fftw-3.3.10/rdft/indirect.d ./Core/Src/fftw-3.3.10/rdft/indirect.o ./Core/Src/fftw-3.3.10/rdft/khc2c.d ./Core/Src/fftw-3.3.10/rdft/khc2c.o ./Core/Src/fftw-3.3.10/rdft/khc2hc.d ./Core/Src/fftw-3.3.10/rdft/khc2hc.o ./Core/Src/fftw-3.3.10/rdft/kr2c.d ./Core/Src/fftw-3.3.10/rdft/kr2c.o ./Core/Src/fftw-3.3.10/rdft/kr2r.d ./Core/Src/fftw-3.3.10/rdft/kr2r.o ./Core/Src/fftw-3.3.10/rdft/nop.d ./Core/Src/fftw-3.3.10/rdft/nop.o ./Core/Src/fftw-3.3.10/rdft/nop2.d ./Core/Src/fftw-3.3.10/rdft/nop2.o ./Core/Src/fftw-3.3.10/rdft/plan.d ./Core/Src/fftw-3.3.10/rdft/plan.o ./Core/Src/fftw-3.3.10/rdft/plan2.d ./Core/Src/fftw-3.3.10/rdft/plan2.o ./Core/Src/fftw-3.3.10/rdft/problem.d ./Core/Src/fftw-3.3.10/rdft/problem.o ./Core/Src/fftw-3.3.10/rdft/problem2.d ./Core/Src/fftw-3.3.10/rdft/problem2.o ./Core/Src/fftw-3.3.10/rdft/rank-geq2-rdft2.d ./Core/Src/fftw-3.3.10/rdft/rank-geq2-rdft2.o ./Core/Src/fftw-3.3.10/rdft/rank-geq2.d ./Core/Src/fftw-3.3.10/rdft/rank-geq2.o ./Core/Src/fftw-3.3.10/rdft/rank0-rdft2.d ./Core/Src/fftw-3.3.10/rdft/rank0-rdft2.o ./Core/Src/fftw-3.3.10/rdft/rank0.d ./Core/Src/fftw-3.3.10/rdft/rank0.o ./Core/Src/fftw-3.3.10/rdft/rdft-dht.d ./Core/Src/fftw-3.3.10/rdft/rdft-dht.o ./Core/Src/fftw-3.3.10/rdft/rdft2-inplace-strides.d ./Core/Src/fftw-3.3.10/rdft/rdft2-inplace-strides.o ./Core/Src/fftw-3.3.10/rdft/rdft2-rdft.d ./Core/Src/fftw-3.3.10/rdft/rdft2-rdft.o ./Core/Src/fftw-3.3.10/rdft/rdft2-strides.d ./Core/Src/fftw-3.3.10/rdft/rdft2-strides.o ./Core/Src/fftw-3.3.10/rdft/rdft2-tensor-max-index.d ./Core/Src/fftw-3.3.10/rdft/rdft2-tensor-max-index.o ./Core/Src/fftw-3.3.10/rdft/solve.d ./Core/Src/fftw-3.3.10/rdft/solve.o ./Core/Src/fftw-3.3.10/rdft/solve2.d ./Core/Src/fftw-3.3.10/rdft/solve2.o ./Core/Src/fftw-3.3.10/rdft/vrank-geq1-rdft2.d ./Core/Src/fftw-3.3.10/rdft/vrank-geq1-rdft2.o ./Core/Src/fftw-3.3.10/rdft/vrank-geq1.d ./Core/Src/fftw-3.3.10/rdft/vrank-geq1.o ./Core/Src/fftw-3.3.10/rdft/vrank3-transpose.d ./Core/Src/fftw-3.3.10/rdft/vrank3-transpose.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-rdft

