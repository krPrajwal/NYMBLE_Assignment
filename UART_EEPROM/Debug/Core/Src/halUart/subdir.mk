################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/halUart/halUart.c 

OBJS += \
./Core/Src/halUart/halUart.o 

C_DEPS += \
./Core/Src/halUart/halUart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/halUart/%.o Core/Src/halUart/%.su Core/Src/halUart/%.cyclo: ../Core/Src/halUart/%.c Core/Src/halUart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/MCU_WORKSPACE/Nymble_pr/UART_EEPROM/Core/Src/halUart" -I"D:/MCU_WORKSPACE/Nymble_pr/UART_EEPROM/Core/Src" -I"D:/MCU_WORKSPACE/Nymble_pr/UART_EEPROM/Core/Src/halEEPROM" -I"D:/MCU_WORKSPACE/Nymble_pr/UART_EEPROM/Core/Src/app" -I"D:/MCU_WORKSPACE/Nymble_pr/UART_EEPROM/Drivers/STM32F4xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-halUart

clean-Core-2f-Src-2f-halUart:
	-$(RM) ./Core/Src/halUart/halUart.cyclo ./Core/Src/halUart/halUart.d ./Core/Src/halUart/halUart.o ./Core/Src/halUart/halUart.su

.PHONY: clean-Core-2f-Src-2f-halUart

