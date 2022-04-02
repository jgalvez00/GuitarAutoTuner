################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/kernel/align.c \
../Core/Src/fftw-3.3.10/kernel/alloc.c \
../Core/Src/fftw-3.3.10/kernel/assert.c \
../Core/Src/fftw-3.3.10/kernel/awake.c \
../Core/Src/fftw-3.3.10/kernel/buffered.c \
../Core/Src/fftw-3.3.10/kernel/cpy1d.c \
../Core/Src/fftw-3.3.10/kernel/cpy2d-pair.c \
../Core/Src/fftw-3.3.10/kernel/cpy2d.c \
../Core/Src/fftw-3.3.10/kernel/ct.c \
../Core/Src/fftw-3.3.10/kernel/debug.c \
../Core/Src/fftw-3.3.10/kernel/extract-reim.c \
../Core/Src/fftw-3.3.10/kernel/hash.c \
../Core/Src/fftw-3.3.10/kernel/iabs.c \
../Core/Src/fftw-3.3.10/kernel/kalloc.c \
../Core/Src/fftw-3.3.10/kernel/md5-1.c \
../Core/Src/fftw-3.3.10/kernel/md5.c \
../Core/Src/fftw-3.3.10/kernel/minmax.c \
../Core/Src/fftw-3.3.10/kernel/ops.c \
../Core/Src/fftw-3.3.10/kernel/pickdim.c \
../Core/Src/fftw-3.3.10/kernel/plan.c \
../Core/Src/fftw-3.3.10/kernel/planner.c \
../Core/Src/fftw-3.3.10/kernel/primes.c \
../Core/Src/fftw-3.3.10/kernel/print.c \
../Core/Src/fftw-3.3.10/kernel/problem.c \
../Core/Src/fftw-3.3.10/kernel/rader.c \
../Core/Src/fftw-3.3.10/kernel/scan.c \
../Core/Src/fftw-3.3.10/kernel/solver.c \
../Core/Src/fftw-3.3.10/kernel/solvtab.c \
../Core/Src/fftw-3.3.10/kernel/stride.c \
../Core/Src/fftw-3.3.10/kernel/tensor.c \
../Core/Src/fftw-3.3.10/kernel/tensor1.c \
../Core/Src/fftw-3.3.10/kernel/tensor2.c \
../Core/Src/fftw-3.3.10/kernel/tensor3.c \
../Core/Src/fftw-3.3.10/kernel/tensor4.c \
../Core/Src/fftw-3.3.10/kernel/tensor5.c \
../Core/Src/fftw-3.3.10/kernel/tensor7.c \
../Core/Src/fftw-3.3.10/kernel/tensor8.c \
../Core/Src/fftw-3.3.10/kernel/tensor9.c \
../Core/Src/fftw-3.3.10/kernel/tile2d.c \
../Core/Src/fftw-3.3.10/kernel/timer.c \
../Core/Src/fftw-3.3.10/kernel/transpose.c \
../Core/Src/fftw-3.3.10/kernel/trig.c \
../Core/Src/fftw-3.3.10/kernel/twiddle.c 

OBJS += \
./Core/Src/fftw-3.3.10/kernel/align.o \
./Core/Src/fftw-3.3.10/kernel/alloc.o \
./Core/Src/fftw-3.3.10/kernel/assert.o \
./Core/Src/fftw-3.3.10/kernel/awake.o \
./Core/Src/fftw-3.3.10/kernel/buffered.o \
./Core/Src/fftw-3.3.10/kernel/cpy1d.o \
./Core/Src/fftw-3.3.10/kernel/cpy2d-pair.o \
./Core/Src/fftw-3.3.10/kernel/cpy2d.o \
./Core/Src/fftw-3.3.10/kernel/ct.o \
./Core/Src/fftw-3.3.10/kernel/debug.o \
./Core/Src/fftw-3.3.10/kernel/extract-reim.o \
./Core/Src/fftw-3.3.10/kernel/hash.o \
./Core/Src/fftw-3.3.10/kernel/iabs.o \
./Core/Src/fftw-3.3.10/kernel/kalloc.o \
./Core/Src/fftw-3.3.10/kernel/md5-1.o \
./Core/Src/fftw-3.3.10/kernel/md5.o \
./Core/Src/fftw-3.3.10/kernel/minmax.o \
./Core/Src/fftw-3.3.10/kernel/ops.o \
./Core/Src/fftw-3.3.10/kernel/pickdim.o \
./Core/Src/fftw-3.3.10/kernel/plan.o \
./Core/Src/fftw-3.3.10/kernel/planner.o \
./Core/Src/fftw-3.3.10/kernel/primes.o \
./Core/Src/fftw-3.3.10/kernel/print.o \
./Core/Src/fftw-3.3.10/kernel/problem.o \
./Core/Src/fftw-3.3.10/kernel/rader.o \
./Core/Src/fftw-3.3.10/kernel/scan.o \
./Core/Src/fftw-3.3.10/kernel/solver.o \
./Core/Src/fftw-3.3.10/kernel/solvtab.o \
./Core/Src/fftw-3.3.10/kernel/stride.o \
./Core/Src/fftw-3.3.10/kernel/tensor.o \
./Core/Src/fftw-3.3.10/kernel/tensor1.o \
./Core/Src/fftw-3.3.10/kernel/tensor2.o \
./Core/Src/fftw-3.3.10/kernel/tensor3.o \
./Core/Src/fftw-3.3.10/kernel/tensor4.o \
./Core/Src/fftw-3.3.10/kernel/tensor5.o \
./Core/Src/fftw-3.3.10/kernel/tensor7.o \
./Core/Src/fftw-3.3.10/kernel/tensor8.o \
./Core/Src/fftw-3.3.10/kernel/tensor9.o \
./Core/Src/fftw-3.3.10/kernel/tile2d.o \
./Core/Src/fftw-3.3.10/kernel/timer.o \
./Core/Src/fftw-3.3.10/kernel/transpose.o \
./Core/Src/fftw-3.3.10/kernel/trig.o \
./Core/Src/fftw-3.3.10/kernel/twiddle.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/kernel/align.d \
./Core/Src/fftw-3.3.10/kernel/alloc.d \
./Core/Src/fftw-3.3.10/kernel/assert.d \
./Core/Src/fftw-3.3.10/kernel/awake.d \
./Core/Src/fftw-3.3.10/kernel/buffered.d \
./Core/Src/fftw-3.3.10/kernel/cpy1d.d \
./Core/Src/fftw-3.3.10/kernel/cpy2d-pair.d \
./Core/Src/fftw-3.3.10/kernel/cpy2d.d \
./Core/Src/fftw-3.3.10/kernel/ct.d \
./Core/Src/fftw-3.3.10/kernel/debug.d \
./Core/Src/fftw-3.3.10/kernel/extract-reim.d \
./Core/Src/fftw-3.3.10/kernel/hash.d \
./Core/Src/fftw-3.3.10/kernel/iabs.d \
./Core/Src/fftw-3.3.10/kernel/kalloc.d \
./Core/Src/fftw-3.3.10/kernel/md5-1.d \
./Core/Src/fftw-3.3.10/kernel/md5.d \
./Core/Src/fftw-3.3.10/kernel/minmax.d \
./Core/Src/fftw-3.3.10/kernel/ops.d \
./Core/Src/fftw-3.3.10/kernel/pickdim.d \
./Core/Src/fftw-3.3.10/kernel/plan.d \
./Core/Src/fftw-3.3.10/kernel/planner.d \
./Core/Src/fftw-3.3.10/kernel/primes.d \
./Core/Src/fftw-3.3.10/kernel/print.d \
./Core/Src/fftw-3.3.10/kernel/problem.d \
./Core/Src/fftw-3.3.10/kernel/rader.d \
./Core/Src/fftw-3.3.10/kernel/scan.d \
./Core/Src/fftw-3.3.10/kernel/solver.d \
./Core/Src/fftw-3.3.10/kernel/solvtab.d \
./Core/Src/fftw-3.3.10/kernel/stride.d \
./Core/Src/fftw-3.3.10/kernel/tensor.d \
./Core/Src/fftw-3.3.10/kernel/tensor1.d \
./Core/Src/fftw-3.3.10/kernel/tensor2.d \
./Core/Src/fftw-3.3.10/kernel/tensor3.d \
./Core/Src/fftw-3.3.10/kernel/tensor4.d \
./Core/Src/fftw-3.3.10/kernel/tensor5.d \
./Core/Src/fftw-3.3.10/kernel/tensor7.d \
./Core/Src/fftw-3.3.10/kernel/tensor8.d \
./Core/Src/fftw-3.3.10/kernel/tensor9.d \
./Core/Src/fftw-3.3.10/kernel/tile2d.d \
./Core/Src/fftw-3.3.10/kernel/timer.d \
./Core/Src/fftw-3.3.10/kernel/transpose.d \
./Core/Src/fftw-3.3.10/kernel/trig.d \
./Core/Src/fftw-3.3.10/kernel/twiddle.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/kernel/%.o: ../Core/Src/fftw-3.3.10/kernel/%.c Core/Src/fftw-3.3.10/kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-kernel

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-kernel:
	-$(RM) ./Core/Src/fftw-3.3.10/kernel/align.d ./Core/Src/fftw-3.3.10/kernel/align.o ./Core/Src/fftw-3.3.10/kernel/alloc.d ./Core/Src/fftw-3.3.10/kernel/alloc.o ./Core/Src/fftw-3.3.10/kernel/assert.d ./Core/Src/fftw-3.3.10/kernel/assert.o ./Core/Src/fftw-3.3.10/kernel/awake.d ./Core/Src/fftw-3.3.10/kernel/awake.o ./Core/Src/fftw-3.3.10/kernel/buffered.d ./Core/Src/fftw-3.3.10/kernel/buffered.o ./Core/Src/fftw-3.3.10/kernel/cpy1d.d ./Core/Src/fftw-3.3.10/kernel/cpy1d.o ./Core/Src/fftw-3.3.10/kernel/cpy2d-pair.d ./Core/Src/fftw-3.3.10/kernel/cpy2d-pair.o ./Core/Src/fftw-3.3.10/kernel/cpy2d.d ./Core/Src/fftw-3.3.10/kernel/cpy2d.o ./Core/Src/fftw-3.3.10/kernel/ct.d ./Core/Src/fftw-3.3.10/kernel/ct.o ./Core/Src/fftw-3.3.10/kernel/debug.d ./Core/Src/fftw-3.3.10/kernel/debug.o ./Core/Src/fftw-3.3.10/kernel/extract-reim.d ./Core/Src/fftw-3.3.10/kernel/extract-reim.o ./Core/Src/fftw-3.3.10/kernel/hash.d ./Core/Src/fftw-3.3.10/kernel/hash.o ./Core/Src/fftw-3.3.10/kernel/iabs.d ./Core/Src/fftw-3.3.10/kernel/iabs.o ./Core/Src/fftw-3.3.10/kernel/kalloc.d ./Core/Src/fftw-3.3.10/kernel/kalloc.o ./Core/Src/fftw-3.3.10/kernel/md5-1.d ./Core/Src/fftw-3.3.10/kernel/md5-1.o ./Core/Src/fftw-3.3.10/kernel/md5.d ./Core/Src/fftw-3.3.10/kernel/md5.o ./Core/Src/fftw-3.3.10/kernel/minmax.d ./Core/Src/fftw-3.3.10/kernel/minmax.o ./Core/Src/fftw-3.3.10/kernel/ops.d ./Core/Src/fftw-3.3.10/kernel/ops.o ./Core/Src/fftw-3.3.10/kernel/pickdim.d ./Core/Src/fftw-3.3.10/kernel/pickdim.o ./Core/Src/fftw-3.3.10/kernel/plan.d ./Core/Src/fftw-3.3.10/kernel/plan.o ./Core/Src/fftw-3.3.10/kernel/planner.d ./Core/Src/fftw-3.3.10/kernel/planner.o ./Core/Src/fftw-3.3.10/kernel/primes.d ./Core/Src/fftw-3.3.10/kernel/primes.o ./Core/Src/fftw-3.3.10/kernel/print.d ./Core/Src/fftw-3.3.10/kernel/print.o ./Core/Src/fftw-3.3.10/kernel/problem.d ./Core/Src/fftw-3.3.10/kernel/problem.o ./Core/Src/fftw-3.3.10/kernel/rader.d ./Core/Src/fftw-3.3.10/kernel/rader.o ./Core/Src/fftw-3.3.10/kernel/scan.d ./Core/Src/fftw-3.3.10/kernel/scan.o ./Core/Src/fftw-3.3.10/kernel/solver.d ./Core/Src/fftw-3.3.10/kernel/solver.o ./Core/Src/fftw-3.3.10/kernel/solvtab.d ./Core/Src/fftw-3.3.10/kernel/solvtab.o ./Core/Src/fftw-3.3.10/kernel/stride.d ./Core/Src/fftw-3.3.10/kernel/stride.o ./Core/Src/fftw-3.3.10/kernel/tensor.d ./Core/Src/fftw-3.3.10/kernel/tensor.o ./Core/Src/fftw-3.3.10/kernel/tensor1.d ./Core/Src/fftw-3.3.10/kernel/tensor1.o ./Core/Src/fftw-3.3.10/kernel/tensor2.d ./Core/Src/fftw-3.3.10/kernel/tensor2.o ./Core/Src/fftw-3.3.10/kernel/tensor3.d ./Core/Src/fftw-3.3.10/kernel/tensor3.o ./Core/Src/fftw-3.3.10/kernel/tensor4.d ./Core/Src/fftw-3.3.10/kernel/tensor4.o ./Core/Src/fftw-3.3.10/kernel/tensor5.d ./Core/Src/fftw-3.3.10/kernel/tensor5.o ./Core/Src/fftw-3.3.10/kernel/tensor7.d ./Core/Src/fftw-3.3.10/kernel/tensor7.o ./Core/Src/fftw-3.3.10/kernel/tensor8.d ./Core/Src/fftw-3.3.10/kernel/tensor8.o ./Core/Src/fftw-3.3.10/kernel/tensor9.d ./Core/Src/fftw-3.3.10/kernel/tensor9.o ./Core/Src/fftw-3.3.10/kernel/tile2d.d ./Core/Src/fftw-3.3.10/kernel/tile2d.o ./Core/Src/fftw-3.3.10/kernel/timer.d ./Core/Src/fftw-3.3.10/kernel/timer.o ./Core/Src/fftw-3.3.10/kernel/transpose.d ./Core/Src/fftw-3.3.10/kernel/transpose.o ./Core/Src/fftw-3.3.10/kernel/trig.d ./Core/Src/fftw-3.3.10/kernel/trig.o ./Core/Src/fftw-3.3.10/kernel/twiddle.d ./Core/Src/fftw-3.3.10/kernel/twiddle.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-kernel

