################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AFIO_Program.c \
../src/App.c \
../src/GPIO_Program.c \
../src/NVIC_Program.c \
../src/RCC_Program.c \
../src/SPI.c \
../src/SysTick_Program.c \
../src/TFT.c 

OBJS += \
./src/AFIO_Program.o \
./src/App.o \
./src/GPIO_Program.o \
./src/NVIC_Program.o \
./src/RCC_Program.o \
./src/SPI.o \
./src/SysTick_Program.o \
./src/TFT.o 

C_DEPS += \
./src/AFIO_Program.d \
./src/App.d \
./src/GPIO_Program.d \
./src/NVIC_Program.d \
./src/RCC_Program.d \
./src/SPI.d \
./src/SysTick_Program.d \
./src/TFT.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


