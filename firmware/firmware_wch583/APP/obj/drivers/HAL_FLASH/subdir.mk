################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/easyflash.c \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_env.c \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_log.c \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_port.c \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_utils.c 

C_DEPS += \
./drivers/HAL_FLASH/easyflash.d \
./drivers/HAL_FLASH/ef_env.d \
./drivers/HAL_FLASH/ef_log.d \
./drivers/HAL_FLASH/ef_port.d \
./drivers/HAL_FLASH/ef_utils.d 

OBJS += \
./drivers/HAL_FLASH/easyflash.o \
./drivers/HAL_FLASH/ef_env.o \
./drivers/HAL_FLASH/ef_log.o \
./drivers/HAL_FLASH/ef_port.o \
./drivers/HAL_FLASH/ef_utils.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/HAL_FLASH/easyflash.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/easyflash.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
drivers/HAL_FLASH/ef_env.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_env.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
drivers/HAL_FLASH/ef_log.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_log.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
drivers/HAL_FLASH/ef_port.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_port.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
drivers/HAL_FLASH/ef_utils.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/HAL_FLASH/ef_utils.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

