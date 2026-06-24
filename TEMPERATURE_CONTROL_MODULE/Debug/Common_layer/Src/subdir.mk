################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Common_layer/Src/Comm_LCD.c \
../Common_layer/Src/com_rtos.c 

OBJS += \
./Common_layer/Src/Comm_LCD.o \
./Common_layer/Src/com_rtos.o 

C_DEPS += \
./Common_layer/Src/Comm_LCD.d \
./Common_layer/Src/com_rtos.d 


# Each subdirectory must supply rules for building sources it contributes
Common_layer/Src/%.o Common_layer/Src/%.su Common_layer/Src/%.cyclo: ../Common_layer/Src/%.c Common_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.19.0/TEMPERATURE_CONTROL_MODULE/Application_layer/Inc" -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.19.0/TEMPERATURE_CONTROL_MODULE/Common_layer/Inc" -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.19.0/TEMPERATURE_CONTROL_MODULE/Project_layer/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common_layer-2f-Src

clean-Common_layer-2f-Src:
	-$(RM) ./Common_layer/Src/Comm_LCD.cyclo ./Common_layer/Src/Comm_LCD.d ./Common_layer/Src/Comm_LCD.o ./Common_layer/Src/Comm_LCD.su ./Common_layer/Src/com_rtos.cyclo ./Common_layer/Src/com_rtos.d ./Common_layer/Src/com_rtos.o ./Common_layer/Src/com_rtos.su

.PHONY: clean-Common_layer-2f-Src

