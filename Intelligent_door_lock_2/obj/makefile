################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Intelligent_door_lock_2.hex \

SECONDARY_LIST += \
Intelligent_door_lock_2.lst \

SECONDARY_SIZE += \
Intelligent_door_lock_2.siz \


# 所有目标
all: Intelligent_door_lock_2.elf secondary-outputs

# 工具调用
Intelligent_door_lock_2.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -T "C:\Users\hp\Desktop\嵌入式比赛\智能门锁\Intelligent_door_lock_2\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"Intelligent_door_lock_2.map" --specs=nano.specs --specs=nosys.specs -o "Intelligent_door_lock_2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
Intelligent_door_lock_2.hex: Intelligent_door_lock_2.elf
	@	riscv-none-embed-objcopy -O ihex "Intelligent_door_lock_2.elf"  "Intelligent_door_lock_2.hex"
	@	@
Intelligent_door_lock_2.lst: Intelligent_door_lock_2.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "Intelligent_door_lock_2.elf" > "Intelligent_door_lock_2.lst"
	@	@
Intelligent_door_lock_2.siz: Intelligent_door_lock_2.elf
	@	riscv-none-embed-size --format=berkeley "Intelligent_door_lock_2.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) Intelligent_door_lock_2.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
