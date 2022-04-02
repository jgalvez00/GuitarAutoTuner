################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/kernel/align.c \
../Core/Src/kernel/alloc.c \
../Core/Src/kernel/assert.c \
../Core/Src/kernel/awake.c \
../Core/Src/kernel/buffered.c \
../Core/Src/kernel/cpy1d.c \
../Core/Src/kernel/cpy2d-pair.c \
../Core/Src/kernel/cpy2d.c \
../Core/Src/kernel/ct.c \
../Core/Src/kernel/debug.c \
../Core/Src/kernel/extract-reim.c \
../Core/Src/kernel/hash.c \
../Core/Src/kernel/iabs.c \
../Core/Src/kernel/kalloc.c \
../Core/Src/kernel/md5-1.c \
../Core/Src/kernel/md5.c \
../Core/Src/kernel/minmax.c \
../Core/Src/kernel/ops.c \
../Core/Src/kernel/pickdim.c \
../Core/Src/kernel/plan.c \
../Core/Src/kernel/planner.c \
../Core/Src/kernel/primes.c \
../Core/Src/kernel/print.c \
../Core/Src/kernel/problem.c \
../Core/Src/kernel/rader.c \
../Core/Src/kernel/scan.c \
../Core/Src/kernel/solver.c \
../Core/Src/kernel/solvtab.c \
../Core/Src/kernel/stride.c \
../Core/Src/kernel/tensor.c \
../Core/Src/kernel/tensor1.c \
../Core/Src/kernel/tensor2.c \
../Core/Src/kernel/tensor3.c \
../Core/Src/kernel/tensor4.c \
../Core/Src/kernel/tensor5.c \
../Core/Src/kernel/tensor7.c \
../Core/Src/kernel/tensor8.c \
../Core/Src/kernel/tensor9.c \
../Core/Src/kernel/tile2d.c \
../Core/Src/kernel/timer.c \
../Core/Src/kernel/transpose.c \
../Core/Src/kernel/trig.c \
../Core/Src/kernel/twiddle.c 

OBJS += \
./Core/Src/kernel/align.o \
./Core/Src/kernel/alloc.o \
./Core/Src/kernel/assert.o \
./Core/Src/kernel/awake.o \
./Core/Src/kernel/buffered.o \
./Core/Src/kernel/cpy1d.o \
./Core/Src/kernel/cpy2d-pair.o \
./Core/Src/kernel/cpy2d.o \
./Core/Src/kernel/ct.o \
./Core/Src/kernel/debug.o \
./Core/Src/kernel/extract-reim.o \
./Core/Src/kernel/hash.o \
./Core/Src/kernel/iabs.o \
./Core/Src/kernel/kalloc.o \
./Core/Src/kernel/md5-1.o \
./Core/Src/kernel/md5.o \
./Core/Src/kernel/minmax.o \
./Core/Src/kernel/ops.o \
./Core/Src/kernel/pickdim.o \
./Core/Src/kernel/plan.o \
./Core/Src/kernel/planner.o \
./Core/Src/kernel/primes.o \
./Core/Src/kernel/print.o \
./Core/Src/kernel/problem.o \
./Core/Src/kernel/rader.o \
./Core/Src/kernel/scan.o \
./Core/Src/kernel/solver.o \
./Core/Src/kernel/solvtab.o \
./Core/Src/kernel/stride.o \
./Core/Src/kernel/tensor.o \
./Core/Src/kernel/tensor1.o \
./Core/Src/kernel/tensor2.o \
./Core/Src/kernel/tensor3.o \
./Core/Src/kernel/tensor4.o \
./Core/Src/kernel/tensor5.o \
./Core/Src/kernel/tensor7.o \
./Core/Src/kernel/tensor8.o \
./Core/Src/kernel/tensor9.o \
./Core/Src/kernel/tile2d.o \
./Core/Src/kernel/timer.o \
./Core/Src/kernel/transpose.o \
./Core/Src/kernel/trig.o \
./Core/Src/kernel/twiddle.o 

C_DEPS += \
./Core/Src/kernel/align.d \
./Core/Src/kernel/alloc.d \
./Core/Src/kernel/assert.d \
./Core/Src/kernel/awake.d \
./Core/Src/kernel/buffered.d \
./Core/Src/kernel/cpy1d.d \
./Core/Src/kernel/cpy2d-pair.d \
./Core/Src/kernel/cpy2d.d \
./Core/Src/kernel/ct.d \
./Core/Src/kernel/debug.d \
./Core/Src/kernel/extract-reim.d \
./Core/Src/kernel/hash.d \
./Core/Src/kernel/iabs.d \
./Core/Src/kernel/kalloc.d \
./Core/Src/kernel/md5-1.d \
./Core/Src/kernel/md5.d \
./Core/Src/kernel/minmax.d \
./Core/Src/kernel/ops.d \
./Core/Src/kernel/pickdim.d \
./Core/Src/kernel/plan.d \
./Core/Src/kernel/planner.d \
./Core/Src/kernel/primes.d \
./Core/Src/kernel/print.d \
./Core/Src/kernel/problem.d \
./Core/Src/kernel/rader.d \
./Core/Src/kernel/scan.d \
./Core/Src/kernel/solver.d \
./Core/Src/kernel/solvtab.d \
./Core/Src/kernel/stride.d \
./Core/Src/kernel/tensor.d \
./Core/Src/kernel/tensor1.d \
./Core/Src/kernel/tensor2.d \
./Core/Src/kernel/tensor3.d \
./Core/Src/kernel/tensor4.d \
./Core/Src/kernel/tensor5.d \
./Core/Src/kernel/tensor7.d \
./Core/Src/kernel/tensor8.d \
./Core/Src/kernel/tensor9.d \
./Core/Src/kernel/tile2d.d \
./Core/Src/kernel/timer.d \
./Core/Src/kernel/transpose.d \
./Core/Src/kernel/trig.d \
./Core/Src/kernel/twiddle.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/kernel/%.o: ../Core/Src/kernel/%.c Core/Src/kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-kernel

clean-Core-2f-Src-2f-kernel:
	-$(RM) ./Core/Src/kernel/align.d ./Core/Src/kernel/align.o ./Core/Src/kernel/alloc.d ./Core/Src/kernel/alloc.o ./Core/Src/kernel/assert.d ./Core/Src/kernel/assert.o ./Core/Src/kernel/awake.d ./Core/Src/kernel/awake.o ./Core/Src/kernel/buffered.d ./Core/Src/kernel/buffered.o ./Core/Src/kernel/cpy1d.d ./Core/Src/kernel/cpy1d.o ./Core/Src/kernel/cpy2d-pair.d ./Core/Src/kernel/cpy2d-pair.o ./Core/Src/kernel/cpy2d.d ./Core/Src/kernel/cpy2d.o ./Core/Src/kernel/ct.d ./Core/Src/kernel/ct.o ./Core/Src/kernel/debug.d ./Core/Src/kernel/debug.o ./Core/Src/kernel/extract-reim.d ./Core/Src/kernel/extract-reim.o ./Core/Src/kernel/hash.d ./Core/Src/kernel/hash.o ./Core/Src/kernel/iabs.d ./Core/Src/kernel/iabs.o ./Core/Src/kernel/kalloc.d ./Core/Src/kernel/kalloc.o ./Core/Src/kernel/md5-1.d ./Core/Src/kernel/md5-1.o ./Core/Src/kernel/md5.d ./Core/Src/kernel/md5.o ./Core/Src/kernel/minmax.d ./Core/Src/kernel/minmax.o ./Core/Src/kernel/ops.d ./Core/Src/kernel/ops.o ./Core/Src/kernel/pickdim.d ./Core/Src/kernel/pickdim.o ./Core/Src/kernel/plan.d ./Core/Src/kernel/plan.o ./Core/Src/kernel/planner.d ./Core/Src/kernel/planner.o ./Core/Src/kernel/primes.d ./Core/Src/kernel/primes.o ./Core/Src/kernel/print.d ./Core/Src/kernel/print.o ./Core/Src/kernel/problem.d ./Core/Src/kernel/problem.o ./Core/Src/kernel/rader.d ./Core/Src/kernel/rader.o ./Core/Src/kernel/scan.d ./Core/Src/kernel/scan.o ./Core/Src/kernel/solver.d ./Core/Src/kernel/solver.o ./Core/Src/kernel/solvtab.d ./Core/Src/kernel/solvtab.o ./Core/Src/kernel/stride.d ./Core/Src/kernel/stride.o ./Core/Src/kernel/tensor.d ./Core/Src/kernel/tensor.o ./Core/Src/kernel/tensor1.d ./Core/Src/kernel/tensor1.o ./Core/Src/kernel/tensor2.d ./Core/Src/kernel/tensor2.o ./Core/Src/kernel/tensor3.d ./Core/Src/kernel/tensor3.o ./Core/Src/kernel/tensor4.d ./Core/Src/kernel/tensor4.o ./Core/Src/kernel/tensor5.d ./Core/Src/kernel/tensor5.o ./Core/Src/kernel/tensor7.d ./Core/Src/kernel/tensor7.o ./Core/Src/kernel/tensor8.d ./Core/Src/kernel/tensor8.o ./Core/Src/kernel/tensor9.d ./Core/Src/kernel/tensor9.o ./Core/Src/kernel/tile2d.d ./Core/Src/kernel/tile2d.o ./Core/Src/kernel/timer.d ./Core/Src/kernel/timer.o ./Core/Src/kernel/transpose.d ./Core/Src/kernel/transpose.o ./Core/Src/kernel/trig.d ./Core/Src/kernel/trig.o ./Core/Src/kernel/twiddle.d ./Core/Src/kernel/twiddle.o

.PHONY: clean-Core-2f-Src-2f-kernel

