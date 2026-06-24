################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_layer/Src/TCM.c 

OBJS += \
./Project_layer/Src/TCM.o 

C_DEPS += \
./Project_layer/Src/TCM.d 


# Each subdirectory must supply rules for building sources it contributes
Project_layer/Src/%.o Project_layer/Src/%.su Project_layer/Src/%.cyclo: ../Project_layer/Src/%.c Project_layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.19.0/TEMPERATURE_CONTROL_MODULE/Application_layer/Inc" -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.19.0/TEMPERATURE_CONTROL_MODULE/Common_layer/Inc" -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.19.0/TEMPERATURE_CONTROL_MODULE/Project_layer/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Project_layer-2f-Src

clean-Project_layer-2f-Src:
	-$(RM) ./Project_layer/Src/TCM.cyclo ./Project_layer/Src/TCM.d ./Project_layer/Src/TCM.o ./Project_layer/Src/TCM.su

.PHONY: clean-Project_layer-2f-Src

