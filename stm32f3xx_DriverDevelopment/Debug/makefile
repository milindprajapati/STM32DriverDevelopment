################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include drivers/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: stm32f3xx_DriverDevelopment.elf

# Tool invocations
stm32f3xx_DriverDevelopment.elf: $(OBJS) $(USER_OBJS) D:\Udemy\Embedded\STM32DriverDevelopment\stm32f3xx_DriverDevelopment/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"D:/Udemy/Embedded/STM32DriverDevelopment/stm32f3xx_DriverDevelopment/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "stm32f3xx_DriverDevelopment.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "stm32f3xx_DriverDevelopment.elf" "stm32f3xx_DriverDevelopment.bin"
	arm-none-eabi-size "stm32f3xx_DriverDevelopment.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
