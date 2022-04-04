################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FFTW_LIBRARY/api/apiplan.c \
../FFTW_LIBRARY/api/execute-dft-c2r.c \
../FFTW_LIBRARY/api/execute-dft-r2c.c \
../FFTW_LIBRARY/api/execute-dft.c \
../FFTW_LIBRARY/api/execute-r2r.c \
../FFTW_LIBRARY/api/execute-split-dft-c2r.c \
../FFTW_LIBRARY/api/execute-split-dft-r2c.c \
../FFTW_LIBRARY/api/execute-split-dft.c \
../FFTW_LIBRARY/api/execute.c \
../FFTW_LIBRARY/api/export-wisdom-to-file.c \
../FFTW_LIBRARY/api/export-wisdom-to-string.c \
../FFTW_LIBRARY/api/export-wisdom.c \
../FFTW_LIBRARY/api/f77api.c \
../FFTW_LIBRARY/api/flops.c \
../FFTW_LIBRARY/api/forget-wisdom.c \
../FFTW_LIBRARY/api/import-system-wisdom.c \
../FFTW_LIBRARY/api/import-wisdom-from-file.c \
../FFTW_LIBRARY/api/import-wisdom-from-string.c \
../FFTW_LIBRARY/api/import-wisdom.c \
../FFTW_LIBRARY/api/malloc.c \
../FFTW_LIBRARY/api/map-r2r-kind.c \
../FFTW_LIBRARY/api/mapflags.c \
../FFTW_LIBRARY/api/mkprinter-file.c \
../FFTW_LIBRARY/api/mkprinter-str.c \
../FFTW_LIBRARY/api/mktensor-iodims.c \
../FFTW_LIBRARY/api/mktensor-iodims64.c \
../FFTW_LIBRARY/api/mktensor-rowmajor.c \
../FFTW_LIBRARY/api/plan-dft-1d.c \
../FFTW_LIBRARY/api/plan-dft-2d.c \
../FFTW_LIBRARY/api/plan-dft-3d.c \
../FFTW_LIBRARY/api/plan-dft-c2r-1d.c \
../FFTW_LIBRARY/api/plan-dft-c2r-2d.c \
../FFTW_LIBRARY/api/plan-dft-c2r-3d.c \
../FFTW_LIBRARY/api/plan-dft-c2r.c \
../FFTW_LIBRARY/api/plan-dft-r2c-1d.c \
../FFTW_LIBRARY/api/plan-dft-r2c-2d.c \
../FFTW_LIBRARY/api/plan-dft-r2c-3d.c \
../FFTW_LIBRARY/api/plan-dft-r2c.c \
../FFTW_LIBRARY/api/plan-dft.c \
../FFTW_LIBRARY/api/plan-guru-dft-c2r.c \
../FFTW_LIBRARY/api/plan-guru-dft-r2c.c \
../FFTW_LIBRARY/api/plan-guru-dft.c \
../FFTW_LIBRARY/api/plan-guru-r2r.c \
../FFTW_LIBRARY/api/plan-guru-split-dft-c2r.c \
../FFTW_LIBRARY/api/plan-guru-split-dft-r2c.c \
../FFTW_LIBRARY/api/plan-guru-split-dft.c \
../FFTW_LIBRARY/api/plan-guru64-dft-c2r.c \
../FFTW_LIBRARY/api/plan-guru64-dft-r2c.c \
../FFTW_LIBRARY/api/plan-guru64-dft.c \
../FFTW_LIBRARY/api/plan-guru64-r2r.c \
../FFTW_LIBRARY/api/plan-guru64-split-dft-c2r.c \
../FFTW_LIBRARY/api/plan-guru64-split-dft-r2c.c \
../FFTW_LIBRARY/api/plan-guru64-split-dft.c \
../FFTW_LIBRARY/api/plan-many-dft-c2r.c \
../FFTW_LIBRARY/api/plan-many-dft-r2c.c \
../FFTW_LIBRARY/api/plan-many-dft.c \
../FFTW_LIBRARY/api/plan-many-r2r.c \
../FFTW_LIBRARY/api/plan-r2r-1d.c \
../FFTW_LIBRARY/api/plan-r2r-2d.c \
../FFTW_LIBRARY/api/plan-r2r-3d.c \
../FFTW_LIBRARY/api/plan-r2r.c \
../FFTW_LIBRARY/api/print-plan.c \
../FFTW_LIBRARY/api/rdft2-pad.c \
../FFTW_LIBRARY/api/the-planner.c 

OBJS += \
./FFTW_LIBRARY/api/apiplan.o \
./FFTW_LIBRARY/api/execute-dft-c2r.o \
./FFTW_LIBRARY/api/execute-dft-r2c.o \
./FFTW_LIBRARY/api/execute-dft.o \
./FFTW_LIBRARY/api/execute-r2r.o \
./FFTW_LIBRARY/api/execute-split-dft-c2r.o \
./FFTW_LIBRARY/api/execute-split-dft-r2c.o \
./FFTW_LIBRARY/api/execute-split-dft.o \
./FFTW_LIBRARY/api/execute.o \
./FFTW_LIBRARY/api/export-wisdom-to-file.o \
./FFTW_LIBRARY/api/export-wisdom-to-string.o \
./FFTW_LIBRARY/api/export-wisdom.o \
./FFTW_LIBRARY/api/f77api.o \
./FFTW_LIBRARY/api/flops.o \
./FFTW_LIBRARY/api/forget-wisdom.o \
./FFTW_LIBRARY/api/import-system-wisdom.o \
./FFTW_LIBRARY/api/import-wisdom-from-file.o \
./FFTW_LIBRARY/api/import-wisdom-from-string.o \
./FFTW_LIBRARY/api/import-wisdom.o \
./FFTW_LIBRARY/api/malloc.o \
./FFTW_LIBRARY/api/map-r2r-kind.o \
./FFTW_LIBRARY/api/mapflags.o \
./FFTW_LIBRARY/api/mkprinter-file.o \
./FFTW_LIBRARY/api/mkprinter-str.o \
./FFTW_LIBRARY/api/mktensor-iodims.o \
./FFTW_LIBRARY/api/mktensor-iodims64.o \
./FFTW_LIBRARY/api/mktensor-rowmajor.o \
./FFTW_LIBRARY/api/plan-dft-1d.o \
./FFTW_LIBRARY/api/plan-dft-2d.o \
./FFTW_LIBRARY/api/plan-dft-3d.o \
./FFTW_LIBRARY/api/plan-dft-c2r-1d.o \
./FFTW_LIBRARY/api/plan-dft-c2r-2d.o \
./FFTW_LIBRARY/api/plan-dft-c2r-3d.o \
./FFTW_LIBRARY/api/plan-dft-c2r.o \
./FFTW_LIBRARY/api/plan-dft-r2c-1d.o \
./FFTW_LIBRARY/api/plan-dft-r2c-2d.o \
./FFTW_LIBRARY/api/plan-dft-r2c-3d.o \
./FFTW_LIBRARY/api/plan-dft-r2c.o \
./FFTW_LIBRARY/api/plan-dft.o \
./FFTW_LIBRARY/api/plan-guru-dft-c2r.o \
./FFTW_LIBRARY/api/plan-guru-dft-r2c.o \
./FFTW_LIBRARY/api/plan-guru-dft.o \
./FFTW_LIBRARY/api/plan-guru-r2r.o \
./FFTW_LIBRARY/api/plan-guru-split-dft-c2r.o \
./FFTW_LIBRARY/api/plan-guru-split-dft-r2c.o \
./FFTW_LIBRARY/api/plan-guru-split-dft.o \
./FFTW_LIBRARY/api/plan-guru64-dft-c2r.o \
./FFTW_LIBRARY/api/plan-guru64-dft-r2c.o \
./FFTW_LIBRARY/api/plan-guru64-dft.o \
./FFTW_LIBRARY/api/plan-guru64-r2r.o \
./FFTW_LIBRARY/api/plan-guru64-split-dft-c2r.o \
./FFTW_LIBRARY/api/plan-guru64-split-dft-r2c.o \
./FFTW_LIBRARY/api/plan-guru64-split-dft.o \
./FFTW_LIBRARY/api/plan-many-dft-c2r.o \
./FFTW_LIBRARY/api/plan-many-dft-r2c.o \
./FFTW_LIBRARY/api/plan-many-dft.o \
./FFTW_LIBRARY/api/plan-many-r2r.o \
./FFTW_LIBRARY/api/plan-r2r-1d.o \
./FFTW_LIBRARY/api/plan-r2r-2d.o \
./FFTW_LIBRARY/api/plan-r2r-3d.o \
./FFTW_LIBRARY/api/plan-r2r.o \
./FFTW_LIBRARY/api/print-plan.o \
./FFTW_LIBRARY/api/rdft2-pad.o \
./FFTW_LIBRARY/api/the-planner.o 

C_DEPS += \
./FFTW_LIBRARY/api/apiplan.d \
./FFTW_LIBRARY/api/execute-dft-c2r.d \
./FFTW_LIBRARY/api/execute-dft-r2c.d \
./FFTW_LIBRARY/api/execute-dft.d \
./FFTW_LIBRARY/api/execute-r2r.d \
./FFTW_LIBRARY/api/execute-split-dft-c2r.d \
./FFTW_LIBRARY/api/execute-split-dft-r2c.d \
./FFTW_LIBRARY/api/execute-split-dft.d \
./FFTW_LIBRARY/api/execute.d \
./FFTW_LIBRARY/api/export-wisdom-to-file.d \
./FFTW_LIBRARY/api/export-wisdom-to-string.d \
./FFTW_LIBRARY/api/export-wisdom.d \
./FFTW_LIBRARY/api/f77api.d \
./FFTW_LIBRARY/api/flops.d \
./FFTW_LIBRARY/api/forget-wisdom.d \
./FFTW_LIBRARY/api/import-system-wisdom.d \
./FFTW_LIBRARY/api/import-wisdom-from-file.d \
./FFTW_LIBRARY/api/import-wisdom-from-string.d \
./FFTW_LIBRARY/api/import-wisdom.d \
./FFTW_LIBRARY/api/malloc.d \
./FFTW_LIBRARY/api/map-r2r-kind.d \
./FFTW_LIBRARY/api/mapflags.d \
./FFTW_LIBRARY/api/mkprinter-file.d \
./FFTW_LIBRARY/api/mkprinter-str.d \
./FFTW_LIBRARY/api/mktensor-iodims.d \
./FFTW_LIBRARY/api/mktensor-iodims64.d \
./FFTW_LIBRARY/api/mktensor-rowmajor.d \
./FFTW_LIBRARY/api/plan-dft-1d.d \
./FFTW_LIBRARY/api/plan-dft-2d.d \
./FFTW_LIBRARY/api/plan-dft-3d.d \
./FFTW_LIBRARY/api/plan-dft-c2r-1d.d \
./FFTW_LIBRARY/api/plan-dft-c2r-2d.d \
./FFTW_LIBRARY/api/plan-dft-c2r-3d.d \
./FFTW_LIBRARY/api/plan-dft-c2r.d \
./FFTW_LIBRARY/api/plan-dft-r2c-1d.d \
./FFTW_LIBRARY/api/plan-dft-r2c-2d.d \
./FFTW_LIBRARY/api/plan-dft-r2c-3d.d \
./FFTW_LIBRARY/api/plan-dft-r2c.d \
./FFTW_LIBRARY/api/plan-dft.d \
./FFTW_LIBRARY/api/plan-guru-dft-c2r.d \
./FFTW_LIBRARY/api/plan-guru-dft-r2c.d \
./FFTW_LIBRARY/api/plan-guru-dft.d \
./FFTW_LIBRARY/api/plan-guru-r2r.d \
./FFTW_LIBRARY/api/plan-guru-split-dft-c2r.d \
./FFTW_LIBRARY/api/plan-guru-split-dft-r2c.d \
./FFTW_LIBRARY/api/plan-guru-split-dft.d \
./FFTW_LIBRARY/api/plan-guru64-dft-c2r.d \
./FFTW_LIBRARY/api/plan-guru64-dft-r2c.d \
./FFTW_LIBRARY/api/plan-guru64-dft.d \
./FFTW_LIBRARY/api/plan-guru64-r2r.d \
./FFTW_LIBRARY/api/plan-guru64-split-dft-c2r.d \
./FFTW_LIBRARY/api/plan-guru64-split-dft-r2c.d \
./FFTW_LIBRARY/api/plan-guru64-split-dft.d \
./FFTW_LIBRARY/api/plan-many-dft-c2r.d \
./FFTW_LIBRARY/api/plan-many-dft-r2c.d \
./FFTW_LIBRARY/api/plan-many-dft.d \
./FFTW_LIBRARY/api/plan-many-r2r.d \
./FFTW_LIBRARY/api/plan-r2r-1d.d \
./FFTW_LIBRARY/api/plan-r2r-2d.d \
./FFTW_LIBRARY/api/plan-r2r-3d.d \
./FFTW_LIBRARY/api/plan-r2r.d \
./FFTW_LIBRARY/api/print-plan.d \
./FFTW_LIBRARY/api/rdft2-pad.d \
./FFTW_LIBRARY/api/the-planner.d 


# Each subdirectory must supply rules for building sources it contributes
FFTW_LIBRARY/api/%.o: ../FFTW_LIBRARY/api/%.c FFTW_LIBRARY/api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g -DDEBUG -DSTM32F091xC -DUSE_HAL_DRIVER -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/Users/markscheker/Library/CloudStorage/OneDrive-purdue.edu/Senior year/spring2022/rec/ADC_test/FFTW_LIBRARY" -I"/Users/markscheker/Library/CloudStorage/OneDrive-purdue.edu/Senior year/spring2022/rec/ADC_test/FFTW_LIBRARY/kernel" -I"/Users/markscheker/Library/CloudStorage/OneDrive-purdue.edu/Senior year/spring2022/rec/ADC_test/FFTW_LIBRARY/rdft" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-FFTW_LIBRARY-2f-api

clean-FFTW_LIBRARY-2f-api:
	-$(RM) ./FFTW_LIBRARY/api/apiplan.d ./FFTW_LIBRARY/api/apiplan.o ./FFTW_LIBRARY/api/execute-dft-c2r.d ./FFTW_LIBRARY/api/execute-dft-c2r.o ./FFTW_LIBRARY/api/execute-dft-r2c.d ./FFTW_LIBRARY/api/execute-dft-r2c.o ./FFTW_LIBRARY/api/execute-dft.d ./FFTW_LIBRARY/api/execute-dft.o ./FFTW_LIBRARY/api/execute-r2r.d ./FFTW_LIBRARY/api/execute-r2r.o ./FFTW_LIBRARY/api/execute-split-dft-c2r.d ./FFTW_LIBRARY/api/execute-split-dft-c2r.o ./FFTW_LIBRARY/api/execute-split-dft-r2c.d ./FFTW_LIBRARY/api/execute-split-dft-r2c.o ./FFTW_LIBRARY/api/execute-split-dft.d ./FFTW_LIBRARY/api/execute-split-dft.o ./FFTW_LIBRARY/api/execute.d ./FFTW_LIBRARY/api/execute.o ./FFTW_LIBRARY/api/export-wisdom-to-file.d ./FFTW_LIBRARY/api/export-wisdom-to-file.o ./FFTW_LIBRARY/api/export-wisdom-to-string.d ./FFTW_LIBRARY/api/export-wisdom-to-string.o ./FFTW_LIBRARY/api/export-wisdom.d ./FFTW_LIBRARY/api/export-wisdom.o ./FFTW_LIBRARY/api/f77api.d ./FFTW_LIBRARY/api/f77api.o ./FFTW_LIBRARY/api/flops.d ./FFTW_LIBRARY/api/flops.o ./FFTW_LIBRARY/api/forget-wisdom.d ./FFTW_LIBRARY/api/forget-wisdom.o ./FFTW_LIBRARY/api/import-system-wisdom.d ./FFTW_LIBRARY/api/import-system-wisdom.o ./FFTW_LIBRARY/api/import-wisdom-from-file.d ./FFTW_LIBRARY/api/import-wisdom-from-file.o ./FFTW_LIBRARY/api/import-wisdom-from-string.d ./FFTW_LIBRARY/api/import-wisdom-from-string.o ./FFTW_LIBRARY/api/import-wisdom.d ./FFTW_LIBRARY/api/import-wisdom.o ./FFTW_LIBRARY/api/malloc.d ./FFTW_LIBRARY/api/malloc.o ./FFTW_LIBRARY/api/map-r2r-kind.d ./FFTW_LIBRARY/api/map-r2r-kind.o ./FFTW_LIBRARY/api/mapflags.d ./FFTW_LIBRARY/api/mapflags.o ./FFTW_LIBRARY/api/mkprinter-file.d ./FFTW_LIBRARY/api/mkprinter-file.o ./FFTW_LIBRARY/api/mkprinter-str.d ./FFTW_LIBRARY/api/mkprinter-str.o ./FFTW_LIBRARY/api/mktensor-iodims.d ./FFTW_LIBRARY/api/mktensor-iodims.o ./FFTW_LIBRARY/api/mktensor-iodims64.d ./FFTW_LIBRARY/api/mktensor-iodims64.o ./FFTW_LIBRARY/api/mktensor-rowmajor.d ./FFTW_LIBRARY/api/mktensor-rowmajor.o ./FFTW_LIBRARY/api/plan-dft-1d.d ./FFTW_LIBRARY/api/plan-dft-1d.o ./FFTW_LIBRARY/api/plan-dft-2d.d ./FFTW_LIBRARY/api/plan-dft-2d.o ./FFTW_LIBRARY/api/plan-dft-3d.d ./FFTW_LIBRARY/api/plan-dft-3d.o ./FFTW_LIBRARY/api/plan-dft-c2r-1d.d ./FFTW_LIBRARY/api/plan-dft-c2r-1d.o ./FFTW_LIBRARY/api/plan-dft-c2r-2d.d ./FFTW_LIBRARY/api/plan-dft-c2r-2d.o ./FFTW_LIBRARY/api/plan-dft-c2r-3d.d ./FFTW_LIBRARY/api/plan-dft-c2r-3d.o ./FFTW_LIBRARY/api/plan-dft-c2r.d ./FFTW_LIBRARY/api/plan-dft-c2r.o ./FFTW_LIBRARY/api/plan-dft-r2c-1d.d ./FFTW_LIBRARY/api/plan-dft-r2c-1d.o ./FFTW_LIBRARY/api/plan-dft-r2c-2d.d ./FFTW_LIBRARY/api/plan-dft-r2c-2d.o ./FFTW_LIBRARY/api/plan-dft-r2c-3d.d ./FFTW_LIBRARY/api/plan-dft-r2c-3d.o ./FFTW_LIBRARY/api/plan-dft-r2c.d ./FFTW_LIBRARY/api/plan-dft-r2c.o ./FFTW_LIBRARY/api/plan-dft.d ./FFTW_LIBRARY/api/plan-dft.o ./FFTW_LIBRARY/api/plan-guru-dft-c2r.d ./FFTW_LIBRARY/api/plan-guru-dft-c2r.o ./FFTW_LIBRARY/api/plan-guru-dft-r2c.d ./FFTW_LIBRARY/api/plan-guru-dft-r2c.o ./FFTW_LIBRARY/api/plan-guru-dft.d ./FFTW_LIBRARY/api/plan-guru-dft.o ./FFTW_LIBRARY/api/plan-guru-r2r.d ./FFTW_LIBRARY/api/plan-guru-r2r.o ./FFTW_LIBRARY/api/plan-guru-split-dft-c2r.d ./FFTW_LIBRARY/api/plan-guru-split-dft-c2r.o ./FFTW_LIBRARY/api/plan-guru-split-dft-r2c.d ./FFTW_LIBRARY/api/plan-guru-split-dft-r2c.o ./FFTW_LIBRARY/api/plan-guru-split-dft.d ./FFTW_LIBRARY/api/plan-guru-split-dft.o ./FFTW_LIBRARY/api/plan-guru64-dft-c2r.d ./FFTW_LIBRARY/api/plan-guru64-dft-c2r.o ./FFTW_LIBRARY/api/plan-guru64-dft-r2c.d ./FFTW_LIBRARY/api/plan-guru64-dft-r2c.o ./FFTW_LIBRARY/api/plan-guru64-dft.d ./FFTW_LIBRARY/api/plan-guru64-dft.o ./FFTW_LIBRARY/api/plan-guru64-r2r.d ./FFTW_LIBRARY/api/plan-guru64-r2r.o ./FFTW_LIBRARY/api/plan-guru64-split-dft-c2r.d ./FFTW_LIBRARY/api/plan-guru64-split-dft-c2r.o ./FFTW_LIBRARY/api/plan-guru64-split-dft-r2c.d ./FFTW_LIBRARY/api/plan-guru64-split-dft-r2c.o ./FFTW_LIBRARY/api/plan-guru64-split-dft.d ./FFTW_LIBRARY/api/plan-guru64-split-dft.o ./FFTW_LIBRARY/api/plan-many-dft-c2r.d ./FFTW_LIBRARY/api/plan-many-dft-c2r.o ./FFTW_LIBRARY/api/plan-many-dft-r2c.d ./FFTW_LIBRARY/api/plan-many-dft-r2c.o ./FFTW_LIBRARY/api/plan-many-dft.d ./FFTW_LIBRARY/api/plan-many-dft.o ./FFTW_LIBRARY/api/plan-many-r2r.d ./FFTW_LIBRARY/api/plan-many-r2r.o ./FFTW_LIBRARY/api/plan-r2r-1d.d ./FFTW_LIBRARY/api/plan-r2r-1d.o ./FFTW_LIBRARY/api/plan-r2r-2d.d ./FFTW_LIBRARY/api/plan-r2r-2d.o ./FFTW_LIBRARY/api/plan-r2r-3d.d ./FFTW_LIBRARY/api/plan-r2r-3d.o ./FFTW_LIBRARY/api/plan-r2r.d ./FFTW_LIBRARY/api/plan-r2r.o ./FFTW_LIBRARY/api/print-plan.d ./FFTW_LIBRARY/api/print-plan.o ./FFTW_LIBRARY/api/rdft2-pad.d ./FFTW_LIBRARY/api/rdft2-pad.o ./FFTW_LIBRARY/api/the-planner.d ./FFTW_LIBRARY/api/the-planner.o

.PHONY: clean-FFTW_LIBRARY-2f-api

