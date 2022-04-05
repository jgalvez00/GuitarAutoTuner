################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/dft/bluestein.c \
../Core/Src/fftw-3.3.10/dft/buffered.c \
../Core/Src/fftw-3.3.10/dft/conf.c \
../Core/Src/fftw-3.3.10/dft/ct.c \
../Core/Src/fftw-3.3.10/dft/dftw-direct.c \
../Core/Src/fftw-3.3.10/dft/dftw-directsq.c \
../Core/Src/fftw-3.3.10/dft/dftw-generic.c \
../Core/Src/fftw-3.3.10/dft/dftw-genericbuf.c \
../Core/Src/fftw-3.3.10/dft/direct.c \
../Core/Src/fftw-3.3.10/dft/generic.c \
../Core/Src/fftw-3.3.10/dft/indirect-transpose.c \
../Core/Src/fftw-3.3.10/dft/indirect.c \
../Core/Src/fftw-3.3.10/dft/kdft-dif.c \
../Core/Src/fftw-3.3.10/dft/kdft-difsq.c \
../Core/Src/fftw-3.3.10/dft/kdft-dit.c \
../Core/Src/fftw-3.3.10/dft/kdft.c \
../Core/Src/fftw-3.3.10/dft/nop.c \
../Core/Src/fftw-3.3.10/dft/plan.c \
../Core/Src/fftw-3.3.10/dft/problem.c \
../Core/Src/fftw-3.3.10/dft/rader.c \
../Core/Src/fftw-3.3.10/dft/rank-geq2.c \
../Core/Src/fftw-3.3.10/dft/solve.c \
../Core/Src/fftw-3.3.10/dft/vrank-geq1.c \
../Core/Src/fftw-3.3.10/dft/zero.c 

OBJS += \
./Core/Src/fftw-3.3.10/dft/bluestein.o \
./Core/Src/fftw-3.3.10/dft/buffered.o \
./Core/Src/fftw-3.3.10/dft/conf.o \
./Core/Src/fftw-3.3.10/dft/ct.o \
./Core/Src/fftw-3.3.10/dft/dftw-direct.o \
./Core/Src/fftw-3.3.10/dft/dftw-directsq.o \
./Core/Src/fftw-3.3.10/dft/dftw-generic.o \
./Core/Src/fftw-3.3.10/dft/dftw-genericbuf.o \
./Core/Src/fftw-3.3.10/dft/direct.o \
./Core/Src/fftw-3.3.10/dft/generic.o \
./Core/Src/fftw-3.3.10/dft/indirect-transpose.o \
./Core/Src/fftw-3.3.10/dft/indirect.o \
./Core/Src/fftw-3.3.10/dft/kdft-dif.o \
./Core/Src/fftw-3.3.10/dft/kdft-difsq.o \
./Core/Src/fftw-3.3.10/dft/kdft-dit.o \
./Core/Src/fftw-3.3.10/dft/kdft.o \
./Core/Src/fftw-3.3.10/dft/nop.o \
./Core/Src/fftw-3.3.10/dft/plan.o \
./Core/Src/fftw-3.3.10/dft/problem.o \
./Core/Src/fftw-3.3.10/dft/rader.o \
./Core/Src/fftw-3.3.10/dft/rank-geq2.o \
./Core/Src/fftw-3.3.10/dft/solve.o \
./Core/Src/fftw-3.3.10/dft/vrank-geq1.o \
./Core/Src/fftw-3.3.10/dft/zero.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/dft/bluestein.d \
./Core/Src/fftw-3.3.10/dft/buffered.d \
./Core/Src/fftw-3.3.10/dft/conf.d \
./Core/Src/fftw-3.3.10/dft/ct.d \
./Core/Src/fftw-3.3.10/dft/dftw-direct.d \
./Core/Src/fftw-3.3.10/dft/dftw-directsq.d \
./Core/Src/fftw-3.3.10/dft/dftw-generic.d \
./Core/Src/fftw-3.3.10/dft/dftw-genericbuf.d \
./Core/Src/fftw-3.3.10/dft/direct.d \
./Core/Src/fftw-3.3.10/dft/generic.d \
./Core/Src/fftw-3.3.10/dft/indirect-transpose.d \
./Core/Src/fftw-3.3.10/dft/indirect.d \
./Core/Src/fftw-3.3.10/dft/kdft-dif.d \
./Core/Src/fftw-3.3.10/dft/kdft-difsq.d \
./Core/Src/fftw-3.3.10/dft/kdft-dit.d \
./Core/Src/fftw-3.3.10/dft/kdft.d \
./Core/Src/fftw-3.3.10/dft/nop.d \
./Core/Src/fftw-3.3.10/dft/plan.d \
./Core/Src/fftw-3.3.10/dft/problem.d \
./Core/Src/fftw-3.3.10/dft/rader.d \
./Core/Src/fftw-3.3.10/dft/rank-geq2.d \
./Core/Src/fftw-3.3.10/dft/solve.d \
./Core/Src/fftw-3.3.10/dft/vrank-geq1.d \
./Core/Src/fftw-3.3.10/dft/zero.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/dft/%.o: ../Core/Src/fftw-3.3.10/dft/%.c Core/Src/fftw-3.3.10/dft/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-dft

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-dft:
	-$(RM) ./Core/Src/fftw-3.3.10/dft/bluestein.d ./Core/Src/fftw-3.3.10/dft/bluestein.o ./Core/Src/fftw-3.3.10/dft/buffered.d ./Core/Src/fftw-3.3.10/dft/buffered.o ./Core/Src/fftw-3.3.10/dft/conf.d ./Core/Src/fftw-3.3.10/dft/conf.o ./Core/Src/fftw-3.3.10/dft/ct.d ./Core/Src/fftw-3.3.10/dft/ct.o ./Core/Src/fftw-3.3.10/dft/dftw-direct.d ./Core/Src/fftw-3.3.10/dft/dftw-direct.o ./Core/Src/fftw-3.3.10/dft/dftw-directsq.d ./Core/Src/fftw-3.3.10/dft/dftw-directsq.o ./Core/Src/fftw-3.3.10/dft/dftw-generic.d ./Core/Src/fftw-3.3.10/dft/dftw-generic.o ./Core/Src/fftw-3.3.10/dft/dftw-genericbuf.d ./Core/Src/fftw-3.3.10/dft/dftw-genericbuf.o ./Core/Src/fftw-3.3.10/dft/direct.d ./Core/Src/fftw-3.3.10/dft/direct.o ./Core/Src/fftw-3.3.10/dft/generic.d ./Core/Src/fftw-3.3.10/dft/generic.o ./Core/Src/fftw-3.3.10/dft/indirect-transpose.d ./Core/Src/fftw-3.3.10/dft/indirect-transpose.o ./Core/Src/fftw-3.3.10/dft/indirect.d ./Core/Src/fftw-3.3.10/dft/indirect.o ./Core/Src/fftw-3.3.10/dft/kdft-dif.d ./Core/Src/fftw-3.3.10/dft/kdft-dif.o ./Core/Src/fftw-3.3.10/dft/kdft-difsq.d ./Core/Src/fftw-3.3.10/dft/kdft-difsq.o ./Core/Src/fftw-3.3.10/dft/kdft-dit.d ./Core/Src/fftw-3.3.10/dft/kdft-dit.o ./Core/Src/fftw-3.3.10/dft/kdft.d ./Core/Src/fftw-3.3.10/dft/kdft.o ./Core/Src/fftw-3.3.10/dft/nop.d ./Core/Src/fftw-3.3.10/dft/nop.o ./Core/Src/fftw-3.3.10/dft/plan.d ./Core/Src/fftw-3.3.10/dft/plan.o ./Core/Src/fftw-3.3.10/dft/problem.d ./Core/Src/fftw-3.3.10/dft/problem.o ./Core/Src/fftw-3.3.10/dft/rader.d ./Core/Src/fftw-3.3.10/dft/rader.o ./Core/Src/fftw-3.3.10/dft/rank-geq2.d ./Core/Src/fftw-3.3.10/dft/rank-geq2.o ./Core/Src/fftw-3.3.10/dft/solve.d ./Core/Src/fftw-3.3.10/dft/solve.o ./Core/Src/fftw-3.3.10/dft/vrank-geq1.d ./Core/Src/fftw-3.3.10/dft/vrank-geq1.o ./Core/Src/fftw-3.3.10/dft/zero.d ./Core/Src/fftw-3.3.10/dft/zero.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-dft

