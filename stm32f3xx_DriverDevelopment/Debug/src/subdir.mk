################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/spi_fd_tx.c 

OBJS += \
./src/spi_fd_tx.o 

C_DEPS += \
./src/spi_fd_tx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F3 -DSTM32F30 -DSTM32F302R8Tx -DNUCLEO_F302R8 -DDEBUG -I"D:/Udemy/Embedded/STM32DriverDevelopment/stm32f3xx_DriverDevelopment/drivers/inc" -I"D:/Udemy/Embedded/STM32DriverDevelopment/stm32f3xx_DriverDevelopment/dev" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


