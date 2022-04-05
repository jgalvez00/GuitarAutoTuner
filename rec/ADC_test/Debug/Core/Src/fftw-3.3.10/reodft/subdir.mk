################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/reodft/conf.c \
../Core/Src/fftw-3.3.10/reodft/redft00e-r2hc-pad.c \
../Core/Src/fftw-3.3.10/reodft/redft00e-r2hc.c \
../Core/Src/fftw-3.3.10/reodft/reodft00e-splitradix.c \
../Core/Src/fftw-3.3.10/reodft/reodft010e-r2hc.c \
../Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc-odd.c \
../Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc.c \
../Core/Src/fftw-3.3.10/reodft/reodft11e-radix2.c \
../Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc-pad.c \
../Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc.c 

OBJS += \
./Core/Src/fftw-3.3.10/reodft/conf.o \
./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc-pad.o \
./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc.o \
./Core/Src/fftw-3.3.10/reodft/reodft00e-splitradix.o \
./Core/Src/fftw-3.3.10/reodft/reodft010e-r2hc.o \
./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc-odd.o \
./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc.o \
./Core/Src/fftw-3.3.10/reodft/reodft11e-radix2.o \
./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc-pad.o \
./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/reodft/conf.d \
./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc-pad.d \
./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc.d \
./Core/Src/fftw-3.3.10/reodft/reodft00e-splitradix.d \
./Core/Src/fftw-3.3.10/reodft/reodft010e-r2hc.d \
./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc-odd.d \
./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc.d \
./Core/Src/fftw-3.3.10/reodft/reodft11e-radix2.d \
./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc-pad.d \
./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/reodft/%.o: ../Core/Src/fftw-3.3.10/reodft/%.c Core/Src/fftw-3.3.10/reodft/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-reodft

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-reodft:
	-$(RM) ./Core/Src/fftw-3.3.10/reodft/conf.d ./Core/Src/fftw-3.3.10/reodft/conf.o ./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc-pad.d ./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc-pad.o ./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc.d ./Core/Src/fftw-3.3.10/reodft/redft00e-r2hc.o ./Core/Src/fftw-3.3.10/reodft/reodft00e-splitradix.d ./Core/Src/fftw-3.3.10/reodft/reodft00e-splitradix.o ./Core/Src/fftw-3.3.10/reodft/reodft010e-r2hc.d ./Core/Src/fftw-3.3.10/reodft/reodft010e-r2hc.o ./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc-odd.d ./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc-odd.o ./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc.d ./Core/Src/fftw-3.3.10/reodft/reodft11e-r2hc.o ./Core/Src/fftw-3.3.10/reodft/reodft11e-radix2.d ./Core/Src/fftw-3.3.10/reodft/reodft11e-radix2.o ./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc-pad.d ./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc-pad.o ./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc.d ./Core/Src/fftw-3.3.10/reodft/rodft00e-r2hc.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-reodft

