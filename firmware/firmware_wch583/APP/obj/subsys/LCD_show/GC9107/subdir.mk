################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/LCD_show/GC9107/lcd.c \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/LCD_show/GC9107/lcd_init.c 

C_DEPS += \
./subsys/LCD_show/GC9107/lcd.d \
./subsys/LCD_show/GC9107/lcd_init.d 

OBJS += \
./subsys/LCD_show/GC9107/lcd.o \
./subsys/LCD_show/GC9107/lcd_init.o 


# Each subdirectory must supply rules for building sources it contributes
subsys/LCD_show/GC9107/lcd.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/LCD_show/GC9107/lcd.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/LCD_show/GC9107/lcd_init.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/LCD_show/GC9107/lcd_init.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DCONFIG_ZTEST -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\pages" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\manager" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

