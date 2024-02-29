################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/halEEPROM/halEeprom.c 

OBJS += \
./Core/Src/halEEPROM/halEeprom.o 

C_DEPS += \
./Core/Src/halEEPROM/halEeprom.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/halEEPROM/%.o Core/Src/halEEPROM/%.su Core/Src/halEEPROM/%.cyclo: ../Core/Src/halEEPROM/%.c Core/Src/halEEPROM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Repo/UART_EEPROM/Core/Src/halUart" -I"D:/Repo/UART_EEPROM/Core/Src" -I"D:/Repo/UART_EEPROM/Core/Src/halEEPROM" -I"D:/Repo/UART_EEPROM/Core/Src/app" -I"D:/Repo/UART_EEPROM/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-halEEPROM

clean-Core-2f-Src-2f-halEEPROM:
	-$(RM) ./Core/Src/halEEPROM/halEeprom.cyclo ./Core/Src/halEEPROM/halEeprom.d ./Core/Src/halEEPROM/halEeprom.o ./Core/Src/halEEPROM/halEeprom.su

.PHONY: clean-Core-2f-Src-2f-halEEPROM

