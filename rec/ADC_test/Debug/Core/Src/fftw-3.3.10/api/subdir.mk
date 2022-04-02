################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fftw-3.3.10/api/apiplan.c \
../Core/Src/fftw-3.3.10/api/configure.c \
../Core/Src/fftw-3.3.10/api/execute-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/execute-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/execute-dft.c \
../Core/Src/fftw-3.3.10/api/execute-r2r.c \
../Core/Src/fftw-3.3.10/api/execute-split-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/execute-split-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/execute-split-dft.c \
../Core/Src/fftw-3.3.10/api/execute.c \
../Core/Src/fftw-3.3.10/api/export-wisdom-to-file.c \
../Core/Src/fftw-3.3.10/api/export-wisdom-to-string.c \
../Core/Src/fftw-3.3.10/api/export-wisdom.c \
../Core/Src/fftw-3.3.10/api/f77api.c \
../Core/Src/fftw-3.3.10/api/flops.c \
../Core/Src/fftw-3.3.10/api/forget-wisdom.c \
../Core/Src/fftw-3.3.10/api/import-system-wisdom.c \
../Core/Src/fftw-3.3.10/api/import-wisdom-from-file.c \
../Core/Src/fftw-3.3.10/api/import-wisdom-from-string.c \
../Core/Src/fftw-3.3.10/api/import-wisdom.c \
../Core/Src/fftw-3.3.10/api/malloc.c \
../Core/Src/fftw-3.3.10/api/map-r2r-kind.c \
../Core/Src/fftw-3.3.10/api/mapflags.c \
../Core/Src/fftw-3.3.10/api/mkprinter-file.c \
../Core/Src/fftw-3.3.10/api/mkprinter-str.c \
../Core/Src/fftw-3.3.10/api/mktensor-iodims.c \
../Core/Src/fftw-3.3.10/api/mktensor-iodims64.c \
../Core/Src/fftw-3.3.10/api/mktensor-rowmajor.c \
../Core/Src/fftw-3.3.10/api/plan-dft-1d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-2d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-3d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-c2r-1d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-c2r-2d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-c2r-3d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/plan-dft-r2c-1d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-r2c-2d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-r2c-3d.c \
../Core/Src/fftw-3.3.10/api/plan-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/plan-dft.c \
../Core/Src/fftw-3.3.10/api/plan-guru-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/plan-guru-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/plan-guru-dft.c \
../Core/Src/fftw-3.3.10/api/plan-guru-r2r.c \
../Core/Src/fftw-3.3.10/api/plan-guru-split-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/plan-guru-split-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/plan-guru-split-dft.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-dft.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-r2r.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/plan-guru64-split-dft.c \
../Core/Src/fftw-3.3.10/api/plan-many-dft-c2r.c \
../Core/Src/fftw-3.3.10/api/plan-many-dft-r2c.c \
../Core/Src/fftw-3.3.10/api/plan-many-dft.c \
../Core/Src/fftw-3.3.10/api/plan-many-r2r.c \
../Core/Src/fftw-3.3.10/api/plan-r2r-1d.c \
../Core/Src/fftw-3.3.10/api/plan-r2r-2d.c \
../Core/Src/fftw-3.3.10/api/plan-r2r-3d.c \
../Core/Src/fftw-3.3.10/api/plan-r2r.c \
../Core/Src/fftw-3.3.10/api/print-plan.c \
../Core/Src/fftw-3.3.10/api/rdft2-pad.c \
../Core/Src/fftw-3.3.10/api/the-planner.c \
../Core/Src/fftw-3.3.10/api/version.c 

OBJS += \
./Core/Src/fftw-3.3.10/api/apiplan.o \
./Core/Src/fftw-3.3.10/api/configure.o \
./Core/Src/fftw-3.3.10/api/execute-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/execute-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/execute-dft.o \
./Core/Src/fftw-3.3.10/api/execute-r2r.o \
./Core/Src/fftw-3.3.10/api/execute-split-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/execute-split-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/execute-split-dft.o \
./Core/Src/fftw-3.3.10/api/execute.o \
./Core/Src/fftw-3.3.10/api/export-wisdom-to-file.o \
./Core/Src/fftw-3.3.10/api/export-wisdom-to-string.o \
./Core/Src/fftw-3.3.10/api/export-wisdom.o \
./Core/Src/fftw-3.3.10/api/f77api.o \
./Core/Src/fftw-3.3.10/api/flops.o \
./Core/Src/fftw-3.3.10/api/forget-wisdom.o \
./Core/Src/fftw-3.3.10/api/import-system-wisdom.o \
./Core/Src/fftw-3.3.10/api/import-wisdom-from-file.o \
./Core/Src/fftw-3.3.10/api/import-wisdom-from-string.o \
./Core/Src/fftw-3.3.10/api/import-wisdom.o \
./Core/Src/fftw-3.3.10/api/malloc.o \
./Core/Src/fftw-3.3.10/api/map-r2r-kind.o \
./Core/Src/fftw-3.3.10/api/mapflags.o \
./Core/Src/fftw-3.3.10/api/mkprinter-file.o \
./Core/Src/fftw-3.3.10/api/mkprinter-str.o \
./Core/Src/fftw-3.3.10/api/mktensor-iodims.o \
./Core/Src/fftw-3.3.10/api/mktensor-iodims64.o \
./Core/Src/fftw-3.3.10/api/mktensor-rowmajor.o \
./Core/Src/fftw-3.3.10/api/plan-dft-1d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-2d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-3d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r-1d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r-2d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r-3d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c-1d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c-2d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c-3d.o \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/plan-dft.o \
./Core/Src/fftw-3.3.10/api/plan-guru-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/plan-guru-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/plan-guru-dft.o \
./Core/Src/fftw-3.3.10/api/plan-guru-r2r.o \
./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/plan-guru-split-dft.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-dft.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-r2r.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft.o \
./Core/Src/fftw-3.3.10/api/plan-many-dft-c2r.o \
./Core/Src/fftw-3.3.10/api/plan-many-dft-r2c.o \
./Core/Src/fftw-3.3.10/api/plan-many-dft.o \
./Core/Src/fftw-3.3.10/api/plan-many-r2r.o \
./Core/Src/fftw-3.3.10/api/plan-r2r-1d.o \
./Core/Src/fftw-3.3.10/api/plan-r2r-2d.o \
./Core/Src/fftw-3.3.10/api/plan-r2r-3d.o \
./Core/Src/fftw-3.3.10/api/plan-r2r.o \
./Core/Src/fftw-3.3.10/api/print-plan.o \
./Core/Src/fftw-3.3.10/api/rdft2-pad.o \
./Core/Src/fftw-3.3.10/api/the-planner.o \
./Core/Src/fftw-3.3.10/api/version.o 

C_DEPS += \
./Core/Src/fftw-3.3.10/api/apiplan.d \
./Core/Src/fftw-3.3.10/api/configure.d \
./Core/Src/fftw-3.3.10/api/execute-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/execute-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/execute-dft.d \
./Core/Src/fftw-3.3.10/api/execute-r2r.d \
./Core/Src/fftw-3.3.10/api/execute-split-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/execute-split-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/execute-split-dft.d \
./Core/Src/fftw-3.3.10/api/execute.d \
./Core/Src/fftw-3.3.10/api/export-wisdom-to-file.d \
./Core/Src/fftw-3.3.10/api/export-wisdom-to-string.d \
./Core/Src/fftw-3.3.10/api/export-wisdom.d \
./Core/Src/fftw-3.3.10/api/f77api.d \
./Core/Src/fftw-3.3.10/api/flops.d \
./Core/Src/fftw-3.3.10/api/forget-wisdom.d \
./Core/Src/fftw-3.3.10/api/import-system-wisdom.d \
./Core/Src/fftw-3.3.10/api/import-wisdom-from-file.d \
./Core/Src/fftw-3.3.10/api/import-wisdom-from-string.d \
./Core/Src/fftw-3.3.10/api/import-wisdom.d \
./Core/Src/fftw-3.3.10/api/malloc.d \
./Core/Src/fftw-3.3.10/api/map-r2r-kind.d \
./Core/Src/fftw-3.3.10/api/mapflags.d \
./Core/Src/fftw-3.3.10/api/mkprinter-file.d \
./Core/Src/fftw-3.3.10/api/mkprinter-str.d \
./Core/Src/fftw-3.3.10/api/mktensor-iodims.d \
./Core/Src/fftw-3.3.10/api/mktensor-iodims64.d \
./Core/Src/fftw-3.3.10/api/mktensor-rowmajor.d \
./Core/Src/fftw-3.3.10/api/plan-dft-1d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-2d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-3d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r-1d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r-2d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r-3d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c-1d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c-2d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c-3d.d \
./Core/Src/fftw-3.3.10/api/plan-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/plan-dft.d \
./Core/Src/fftw-3.3.10/api/plan-guru-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/plan-guru-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/plan-guru-dft.d \
./Core/Src/fftw-3.3.10/api/plan-guru-r2r.d \
./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/plan-guru-split-dft.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-dft.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-r2r.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft.d \
./Core/Src/fftw-3.3.10/api/plan-many-dft-c2r.d \
./Core/Src/fftw-3.3.10/api/plan-many-dft-r2c.d \
./Core/Src/fftw-3.3.10/api/plan-many-dft.d \
./Core/Src/fftw-3.3.10/api/plan-many-r2r.d \
./Core/Src/fftw-3.3.10/api/plan-r2r-1d.d \
./Core/Src/fftw-3.3.10/api/plan-r2r-2d.d \
./Core/Src/fftw-3.3.10/api/plan-r2r-3d.d \
./Core/Src/fftw-3.3.10/api/plan-r2r.d \
./Core/Src/fftw-3.3.10/api/print-plan.d \
./Core/Src/fftw-3.3.10/api/rdft2-pad.d \
./Core/Src/fftw-3.3.10/api/the-planner.d \
./Core/Src/fftw-3.3.10/api/version.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/fftw-3.3.10/api/%.o: ../Core/Src/fftw-3.3.10/api/%.c Core/Src/fftw-3.3.10/api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-api

clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-api:
	-$(RM) ./Core/Src/fftw-3.3.10/api/apiplan.d ./Core/Src/fftw-3.3.10/api/apiplan.o ./Core/Src/fftw-3.3.10/api/configure.d ./Core/Src/fftw-3.3.10/api/configure.o ./Core/Src/fftw-3.3.10/api/execute-dft-c2r.d ./Core/Src/fftw-3.3.10/api/execute-dft-c2r.o ./Core/Src/fftw-3.3.10/api/execute-dft-r2c.d ./Core/Src/fftw-3.3.10/api/execute-dft-r2c.o ./Core/Src/fftw-3.3.10/api/execute-dft.d ./Core/Src/fftw-3.3.10/api/execute-dft.o ./Core/Src/fftw-3.3.10/api/execute-r2r.d ./Core/Src/fftw-3.3.10/api/execute-r2r.o ./Core/Src/fftw-3.3.10/api/execute-split-dft-c2r.d ./Core/Src/fftw-3.3.10/api/execute-split-dft-c2r.o ./Core/Src/fftw-3.3.10/api/execute-split-dft-r2c.d ./Core/Src/fftw-3.3.10/api/execute-split-dft-r2c.o ./Core/Src/fftw-3.3.10/api/execute-split-dft.d ./Core/Src/fftw-3.3.10/api/execute-split-dft.o ./Core/Src/fftw-3.3.10/api/execute.d ./Core/Src/fftw-3.3.10/api/execute.o ./Core/Src/fftw-3.3.10/api/export-wisdom-to-file.d ./Core/Src/fftw-3.3.10/api/export-wisdom-to-file.o ./Core/Src/fftw-3.3.10/api/export-wisdom-to-string.d ./Core/Src/fftw-3.3.10/api/export-wisdom-to-string.o ./Core/Src/fftw-3.3.10/api/export-wisdom.d ./Core/Src/fftw-3.3.10/api/export-wisdom.o ./Core/Src/fftw-3.3.10/api/f77api.d ./Core/Src/fftw-3.3.10/api/f77api.o ./Core/Src/fftw-3.3.10/api/flops.d ./Core/Src/fftw-3.3.10/api/flops.o ./Core/Src/fftw-3.3.10/api/forget-wisdom.d ./Core/Src/fftw-3.3.10/api/forget-wisdom.o ./Core/Src/fftw-3.3.10/api/import-system-wisdom.d ./Core/Src/fftw-3.3.10/api/import-system-wisdom.o ./Core/Src/fftw-3.3.10/api/import-wisdom-from-file.d ./Core/Src/fftw-3.3.10/api/import-wisdom-from-file.o ./Core/Src/fftw-3.3.10/api/import-wisdom-from-string.d ./Core/Src/fftw-3.3.10/api/import-wisdom-from-string.o ./Core/Src/fftw-3.3.10/api/import-wisdom.d ./Core/Src/fftw-3.3.10/api/import-wisdom.o ./Core/Src/fftw-3.3.10/api/malloc.d ./Core/Src/fftw-3.3.10/api/malloc.o ./Core/Src/fftw-3.3.10/api/map-r2r-kind.d ./Core/Src/fftw-3.3.10/api/map-r2r-kind.o ./Core/Src/fftw-3.3.10/api/mapflags.d ./Core/Src/fftw-3.3.10/api/mapflags.o ./Core/Src/fftw-3.3.10/api/mkprinter-file.d ./Core/Src/fftw-3.3.10/api/mkprinter-file.o ./Core/Src/fftw-3.3.10/api/mkprinter-str.d ./Core/Src/fftw-3.3.10/api/mkprinter-str.o ./Core/Src/fftw-3.3.10/api/mktensor-iodims.d ./Core/Src/fftw-3.3.10/api/mktensor-iodims.o ./Core/Src/fftw-3.3.10/api/mktensor-iodims64.d ./Core/Src/fftw-3.3.10/api/mktensor-iodims64.o ./Core/Src/fftw-3.3.10/api/mktensor-rowmajor.d ./Core/Src/fftw-3.3.10/api/mktensor-rowmajor.o ./Core/Src/fftw-3.3.10/api/plan-dft-1d.d ./Core/Src/fftw-3.3.10/api/plan-dft-1d.o ./Core/Src/fftw-3.3.10/api/plan-dft-2d.d ./Core/Src/fftw-3.3.10/api/plan-dft-2d.o ./Core/Src/fftw-3.3.10/api/plan-dft-3d.d ./Core/Src/fftw-3.3.10/api/plan-dft-3d.o ./Core/Src/fftw-3.3.10/api/plan-dft-c2r-1d.d ./Core/Src/fftw-3.3.10/api/plan-dft-c2r-1d.o ./Core/Src/fftw-3.3.10/api/plan-dft-c2r-2d.d ./Core/Src/fftw-3.3.10/api/plan-dft-c2r-2d.o ./Core/Src/fftw-3.3.10/api/plan-dft-c2r-3d.d ./Core/Src/fftw-3.3.10/api/plan-dft-c2r-3d.o ./Core/Src/fftw-3.3.10/api/plan-dft-c2r.d ./Core/Src/fftw-3.3.10/api/plan-dft-c2r.o ./Core/Src/fftw-3.3.10/api/plan-dft-r2c-1d.d ./Core/Src/fftw-3.3.10/api/plan-dft-r2c-1d.o ./Core/Src/fftw-3.3.10/api/plan-dft-r2c-2d.d ./Core/Src/fftw-3.3.10/api/plan-dft-r2c-2d.o ./Core/Src/fftw-3.3.10/api/plan-dft-r2c-3d.d ./Core/Src/fftw-3.3.10/api/plan-dft-r2c-3d.o ./Core/Src/fftw-3.3.10/api/plan-dft-r2c.d ./Core/Src/fftw-3.3.10/api/plan-dft-r2c.o ./Core/Src/fftw-3.3.10/api/plan-dft.d ./Core/Src/fftw-3.3.10/api/plan-dft.o ./Core/Src/fftw-3.3.10/api/plan-guru-dft-c2r.d ./Core/Src/fftw-3.3.10/api/plan-guru-dft-c2r.o ./Core/Src/fftw-3.3.10/api/plan-guru-dft-r2c.d ./Core/Src/fftw-3.3.10/api/plan-guru-dft-r2c.o ./Core/Src/fftw-3.3.10/api/plan-guru-dft.d ./Core/Src/fftw-3.3.10/api/plan-guru-dft.o ./Core/Src/fftw-3.3.10/api/plan-guru-r2r.d ./Core/Src/fftw-3.3.10/api/plan-guru-r2r.o ./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-c2r.d ./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-c2r.o ./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-r2c.d ./Core/Src/fftw-3.3.10/api/plan-guru-split-dft-r2c.o ./Core/Src/fftw-3.3.10/api/plan-guru-split-dft.d ./Core/Src/fftw-3.3.10/api/plan-guru-split-dft.o ./Core/Src/fftw-3.3.10/api/plan-guru64-dft-c2r.d ./Core/Src/fftw-3.3.10/api/plan-guru64-dft-c2r.o ./Core/Src/fftw-3.3.10/api/plan-guru64-dft-r2c.d ./Core/Src/fftw-3.3.10/api/plan-guru64-dft-r2c.o ./Core/Src/fftw-3.3.10/api/plan-guru64-dft.d ./Core/Src/fftw-3.3.10/api/plan-guru64-dft.o ./Core/Src/fftw-3.3.10/api/plan-guru64-r2r.d ./Core/Src/fftw-3.3.10/api/plan-guru64-r2r.o ./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-c2r.d ./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-c2r.o ./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-r2c.d ./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft-r2c.o ./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft.d ./Core/Src/fftw-3.3.10/api/plan-guru64-split-dft.o ./Core/Src/fftw-3.3.10/api/plan-many-dft-c2r.d ./Core/Src/fftw-3.3.10/api/plan-many-dft-c2r.o ./Core/Src/fftw-3.3.10/api/plan-many-dft-r2c.d ./Core/Src/fftw-3.3.10/api/plan-many-dft-r2c.o ./Core/Src/fftw-3.3.10/api/plan-many-dft.d ./Core/Src/fftw-3.3.10/api/plan-many-dft.o ./Core/Src/fftw-3.3.10/api/plan-many-r2r.d ./Core/Src/fftw-3.3.10/api/plan-many-r2r.o ./Core/Src/fftw-3.3.10/api/plan-r2r-1d.d ./Core/Src/fftw-3.3.10/api/plan-r2r-1d.o ./Core/Src/fftw-3.3.10/api/plan-r2r-2d.d ./Core/Src/fftw-3.3.10/api/plan-r2r-2d.o ./Core/Src/fftw-3.3.10/api/plan-r2r-3d.d ./Core/Src/fftw-3.3.10/api/plan-r2r-3d.o ./Core/Src/fftw-3.3.10/api/plan-r2r.d ./Core/Src/fftw-3.3.10/api/plan-r2r.o ./Core/Src/fftw-3.3.10/api/print-plan.d ./Core/Src/fftw-3.3.10/api/print-plan.o ./Core/Src/fftw-3.3.10/api/rdft2-pad.d ./Core/Src/fftw-3.3.10/api/rdft2-pad.o ./Core/Src/fftw-3.3.10/api/the-planner.d ./Core/Src/fftw-3.3.10/api/the-planner.o ./Core/Src/fftw-3.3.10/api/version.d ./Core/Src/fftw-3.3.10/api/version.o

.PHONY: clean-Core-2f-Src-2f-fftw-2d-3-2e-3-2e-10-2f-api

