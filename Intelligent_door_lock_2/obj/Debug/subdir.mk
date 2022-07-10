################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Debug/debug.c 

OBJS += \
./Debug/debug.o 

C_DEPS += \
./Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
Debug/%.o: ../Debug/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Debug" -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Core" -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\User" -I"C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

