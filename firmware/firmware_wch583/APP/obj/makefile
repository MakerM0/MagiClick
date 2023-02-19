################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subsys/sensor/SHT30/subdir.mk
-include subsys/sensor/subdir.mk
-include subsys/LCD_show/pages/temperature/subdir.mk
-include subsys/LCD_show/pages/stopwatch/subdir.mk
-include subsys/LCD_show/pages/shutter/subdir.mk
-include subsys/LCD_show/pages/media/subdir.mk
-include subsys/LCD_show/pages/lucky/subdir.mk
-include subsys/LCD_show/pages/counter/subdir.mk
-include subsys/LCD_show/pages/clock/subdir.mk
-include subsys/LCD_show/pages/subdir.mk
-include subsys/LCD_show/manager/subdir.mk
-include subsys/LCD_show/UGUI/Fonts/subdir.mk
-include subsys/LCD_show/UGUI/subdir.mk
-include subsys/LCD_show/GC9107/subdir.mk
-include subsys/LCD_show/subdir.mk
-include subsys/HAL/subdir.mk
-include subsys/BLE/profile/subdir.mk
-include subsys/BLE/subdir.mk
-include src/subdir.mk
-include soc/subdir.mk
-include drivers/dfu/subdir.mk
-include drivers/debug/subdir.mk
-include drivers/SPI/subdir.mk
-include drivers/RingBuffer/subdir.mk
-include drivers/I2C/subdir.mk
-include drivers/HAL_FLASH/subdir.mk
-include drivers/GPIO/subdir.mk
-include drivers/Button2/subdir.mk
-include arch/subdir.mk
-include StdPeriphDriver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
MagiClick.bin \

SECONDARY_LIST += \
MagiClick.lst \

SECONDARY_SIZE += \
MagiClick.siz \


# All Target
all: MagiClick.elf secondary-outputs

# Tool invocations
MagiClick.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -T "../../soc/Link.ld" -nostartfiles -Xlinker --gc-sections -L"../../LIB" -Xlinker --print-memory-usage -Wl,-Map,"MagiClick.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -o "MagiClick.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
MagiClick.bin: MagiClick.elf
	@	riscv-none-embed-objcopy -O binary "MagiClick.elf"  "MagiClick.bin"
	@	@
MagiClick.lst: MagiClick.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "MagiClick.elf" > "MagiClick.lst"
	@	@
MagiClick.siz: MagiClick.elf
	@	riscv-none-embed-size --format=berkeley "MagiClick.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(C_DEPS)$(CC_DEPS)$(ASM_UPPER_DEPS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(SECONDARY_FLASH)$(ASM_DEPS)$(S_UPPER_DEPS)$(CPP_DEPS) MagiClick.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
