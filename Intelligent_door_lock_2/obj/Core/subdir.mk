################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Niming.c \
../Core/PWM.c \
../Core/as608.c \
../Core/core_riscv.c \
../Core/display.c \
../Core/key.c \
../Core/lcd.c \
../Core/timer.c \
../Core/uart_opwnmv.c \
../Core/usart2.c \
../Core/use_as608.c 

OBJS += \
./Core/Niming.o \
./Core/PWM.o \
./Core/as608.o \
./Core/core_riscv.o \
./Core/display.o \
./Core/key.o \
./Core/lcd.o \
./Core/timer.o \
./Core/uart_opwnmv.o \
./Core/usart2.o \
./Core/use_as608.o 

C_DEPS += \
./Core/Niming.d \
./Core/PWM.d \
./Core/as608.d \
./Core/core_riscv.d \
./Core/display.d \
./Core/key.d \
./Core/lcd.d \
./Core/timer.d \
./Core/uart_opwnmv.d \
./Core/usart2.d \
./Core/use_as608.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Debug" -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Core" -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\User" -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

